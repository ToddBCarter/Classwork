#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



unsigned int makeint(unsigned char buf[], int blkpos)
  {
   return buf[blkpos+1] << 8 | buf[blkpos];
  }  //END makeint

unsigned int makeint4(unsigned char buf[], int blockpos)
  {
   return buf[blockpos+3] << 24 | buf[blockpos+2] << 16 | 
          buf[blockpos+1] << 8 | buf[blockpos];
  }  //END makeint



int main(int argc, char **argv)
  {
   char fname[50];          // Holds disk image file name
   int fd;                  // UNIX file descriptor
   unsigned char buf[5120]; // character buffer
   int numbytesread;        // actual no of bytes read from file
   int pos, seekpos;        // pos = desired byte position, sekkpos = actual
   int blocknum;            // block number to seek to
   int perline = 16;        // number of values (bytes printed per line
   unsigned short int val;  // holds int value of two bytes
   int i,j;
   
 /* 
  * Get file name from command line if supplied, otherwise prompt for it
  */
   if(argc == 2)
     {
      strcpy(fname, argv[1]);
     }	 
   else
     {
      printf("Enter name of file to open: ");
      scanf("%s", fname);
     }
	    
   printf("\nOpening %s\n", fname);
   fd = open(fname, O_RDONLY);
	       
   if(fd <= 0)
     {
      printf("Something bad happened opening file - bye\n");
      exit(1);
     }

 /* 
  * The following three lines aren't necessary here, but shows how to move 
  * the file pointer to the start of block number 'blocknum'
  */
   blocknum = 19;
   pos = blocknum * 512;
   seekpos = lseek(fd, pos, SEEK_SET);

   numbytesread = read(fd, buf, 512);
   printf("Read %d bytes from file\n\n", numbytesread);

 /*
  * Headings for table
  */
   printf("StartByte|");
   for(j = perline -1; j >= 0; j--)
      printf("%3d ", j);
   printf(" |\n");
   printf(" Dec Hex |");
   for(j = perline -1; j >= 0; j--)
      printf(" %02X ", j);
   printf(" |\n");
   for(j = 0; j < 75; j++)
      printf("_");
   printf("|\n");
 
 /*
  * Print out block, "perline" values per line. Both hex and character values
  * are printed.
  */
   for(i = 0; i < numbytesread; i+=perline)
     {
      printf("%4d %03X |", i, i);
      for(j = i + perline - 1; j >= i; j--)
         printf(" %02X ", buf[j]);
      printf( " |\n         |");

      for(j = i + perline - 1; j >= i; j--)
        {
         if(buf[j] < 32 || buf[j] > 126)
            printf("  . ");
         else
            printf("  %c ",buf[j]);
        }  // END for j
      printf( " |\n         |");

      for(j = i + perline - 1; j >= i; j-=2)
        {
         val = buf[j] << 8 | buf[j-1];
         printf("  %5d ", val);
        }
      printf(" |\n\n");

     }  // END for i
   
   printf("\n");
   
/*
 * Parameters extracted from boot block.  
 */

   unsigned int bpb, rb, nerd, nblocks, bpf, spt, nheads, hb;
   unsigned char bpc, nFAT, meddesc;

   printf("First 3 bytes - jmp <bootstrap> %x %x %x\n",buf[0x0], buf[0x1], 
		                                       buf[0x2]);
   printf("Mfg Name - %c%c%c%c%c%c%c%c\n", buf[3], buf[4], buf[5], buf[6],
                                           buf[7], buf[8], buf[9], buf[0x0a]);
   bpb = makeint(buf,0x0b);     // Bytes per block
   bpc = buf[0x0d];             // Blocks per cluster
   rb = makeint(buf,0x0e);      // Reserved blocks
   nFAT = buf[0x10];            // Number of FATs
   nerd = makeint(buf,0x11);    // Number of root directory entries
   nblocks = makeint(buf,0x13); // Number of blocks on disk
   meddesc = buf[0x15];         // Medium Descriptor
   bpf = makeint(buf,0x16);     // Number of blocks per FAT
   spt = makeint(buf,0x18);     // Sectors per track
   nheads = makeint(buf,0x1a);  // Number of heads
   hb = makeint(buf,0x1c);      // Number of hissen blocks

   printf("Bytes per block - %d\n", bpb);
   printf("Blocks per cluster - %d\n", bpc);
   printf("Reserved blocks - %d\n", rb);
   printf("Number of FATs - %d\n", nFAT);
   printf("Number of root directory entries - %d\n", nerd);
   printf("Number of blocks on disk - %d\n", nblocks);
   printf("Medium Descriptor - %d\n", meddesc);
   printf("Number of blocks per FAT - %d\n", bpf);
   printf("Sectors per track - %d\n", spt);
   printf("Number of heads - %d\n", nheads);
   printf("Number of hidden blocks - %d\n\n", hb); 

/*
 * The following values are calculated from the above parameters
 */

   unsigned int FATstrt[10]; // Starting block number of each FAT
   unsigned int rootstrt;    // starting block of root directory
   unsigned int nRoot;       // Numnber of block in root directory
   unsigned int datastrt;    // Starting block of data section of disk
  
   for( i=0; i < nFAT; i++)
     {
      FATstrt[i] = hb + rb + i*bpf;  // Starting block number of each FAT
      printf("Starting block number of FAT number %d - %d\n", i, FATstrt[i]);
     }
 
   rootstrt = FATstrt[nFAT-1] + bpf;
   nRoot = (nerd*32 + bpb)/ bpb;
   datastrt = rootstrt + nRoot;

   printf("Starting block of root directory - %d\n", rootstrt);
   printf("Number blocks in root directory - %d\n", nRoot);
   printf("Starting block number of data on disk - %d\n", datastrt);
 
 
/*
	Blocks needed:
		location of root = Length of boot + (number of FATs * number of blocks per FAT)
			length of boot = location of first FAT
			location of first FAT = hb + rb from boot
		
		location of data = location of root + length of root
			length of root = (nerd*32 + bpb - 1) / bpb
			(All data is in bytes, so need to convert to chars to get ASCII)
		
*/
 
   blocknum = 0; //This sets the current block
   
   unsigned int firstFATLoc = rb + hb;
   unsigned int rootLoc = firstFATLoc + (nFAT * bpf);
   
   blocknum = rootLoc;
   
   
   
   pos = blocknum * 512;
   seekpos = lseek(fd, pos, SEEK_SET);

   numbytesread = read(fd, buf, 512);
   printf("Read %d bytes from file\n\n", numbytesread);
 
 
 
 
 
  } //END main
   
