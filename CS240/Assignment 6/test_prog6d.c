/*
CS240
Assignment 6
Todd Carter
cart7982@vandals.uidaho.edu
4-2-2024
*/


/*


*/


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



/*
* This function is meant to find the next cluster after being passed
* a cluster from main().
*
*  It does not work.  This is far from the first version as well.
*
*/
unsigned short getcluster(FILE *fd, unsigned short cluster)
{
	unsigned short nextCluster;
	unsigned char bytes[2];
	
	//Set up offset:
	long offset = 1.5 * cluster;
	
	//Move to the offset to get new cluster:
	fseek(fd, offset, SEEK_SET);
	
	//Read the new cluster:
	fread(bytes, sizeof(unsigned char), 2, fd);
	
	//Modulus to check if upper or lower:
	if (cluster % 2 == 0)
	{
		nextCluster = ((bytes[1] & 0x0F) << 8) | bytes[0];
	}
	else
	{
		nextCluster = (bytes[1] << 4) | ((bytes[0]) >> 4);
	}
	
	//End check:
	if (nextCluster >= 0xFF8)
	{
		printf("\nError!  End of cluster found!\n");
		return 0;
	}
	
	return nextCluster;
}


/*
 *  This function uses the table printing style provided for the assignment
 *  for the sake of debugging and looking at the FATs.
 */
void printBlock(unsigned char buf[], int perline, int numbytesread)
{   
   int i, j;
   unsigned short val;
   
   //Header information.   
   printf("\nStartByte|");
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
  * Print out block, "perline" values per line. 
  * Both hex and character values are printed.
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
}





/*
   rootInformation() prints the information found in
   the root directory... maybe.
   The root directory found for floppy2.img indicated that this
   likely does not work correctly, as the file type is "1st."
*/
void rootInformation(unsigned char buf[])
{
   unsigned int timeCre = makeint(buf,0x16);
   unsigned int dateCre = makeint(buf, 0x18);
   if(buf[0] != 0)
   {
	   printf("\nFilename: %c%c%c%c%c%c%c%c\n", buf[0], buf[1], buf[2], buf[3],
											   buf[4], buf[5], buf[6], buf[7]);
	   
	   printf("Filename extension: %c%c%c\n", buf[8], buf[9], buf[0x0a]);
	   printf("File attributes: %02X\n", buf[0x0b]);
	   printf("Cluster number: %d\n", (((buf[0x1b] & 0x0f) << 8) | buf[0x1a]));
	   printf("File size: %d\n", makeint4(buf, 0x1c));
	   
	   int hour = timeCre >> 11;
	   int minute = (timeCre >> 5) & 0x3F;
	   int second = (timeCre & 0x1F) * 2;

	   //printf("Time created: %02d:%02d:%02d\n", hour, minute, second);
	   
	   int day = dateCre & 0x1F;
	   int month = (dateCre >> 5) & 0x0F;
	   int year = ((dateCre >> 9) & 0x7F) + 1980;
	   
	   //printf("Date created: %02d:%02d:%02d\n", day, month, year);
	   
	   unsigned int fileStart = makeint(buf,0x1a);
	   
   }
}


void printData(unsigned char buf[], int numbytesread)
{
	int perline = 16;
	for(int j = 0; j < (numbytesread/perline)+1; j++)
      {
	     for(int i = j * perline; i < ((j * perline) + perline); i++)
	     {
	        printf("%c", buf[i]);
	     }
	     printf("\n");
      }
}


/*
Some of this is just a modified version of the dumpfile.
*/
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
   unsigned short cln;
   
   unsigned char buf2[3];
   unsigned char fbuf[33];
   
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
   
   
   	 
   //======================================
  /*
   * Boot block information:
   */
   blocknum = 0;
   pos = blocknum * 512;   
   perline = 16;  //This is only used for printing the blocks.
   seekpos = lseek(fd, pos, SEEK_SET);
   numbytesread = read(fd, buf, 512);
   //printBlock(buf, perline, numbytesread);
  
 /*
  * Parameters extracted from boot block,
  * as demonstrated in assignment materials:
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
   unsigned int nRoot;       // Numnber of blocks in root directory
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
   
   
   
   //=============================
  /*
   * Root directory information:
   */   
   
   
   //Alternate ways of calculating these parameters:
   unsigned int firstFATLoc = rb + hb;  //First FAT block location.
   unsigned int rootLoc = firstFATLoc + (nFAT * bpf);  //First root block.
   unsigned int rootBlks = (nerd*32 + bpb - 1) / bpb;  //Number of root blocks,
														//per the lecture slides.
   unsigned int endOfRoot = rootLoc + rootBlks;  //Last block of the root directory.
   
   
   
   perline = 16;
   
   
   //Print out the file names and information:
   pos = rootLoc * 512;
   lseek(fd, pos, SEEK_SET);
   read(fd, buf, 32);
   rootInformation(buf);   
   i = 1;
   while(i < nerd)
   { 
      read(fd, buf, 32);
      rootInformation(buf);
	  i++;
   }
   
   
   //Changing i changes which file is used:
   i = 11;
   pos = (rootLoc * 512) + (32 * i);
   lseek(fd, pos, SEEK_SET);
   read(fd, buf, 32);
   printf("\nFile being used is: \n");
   rootInformation(buf);
   
   //Attempt to get cluster from first blocks of root:
   //printf("\nbuf is %02X\n",buf[0x0a]);
   //printf("\nroot buf 0x1a is %02X\n",buf[0x1a]);
   //printf("root buf 0x1b is %02X\n",buf[0x1b]);
   printf("\nRoot cluster numbers are: %02X %02X\n", buf[0x1b], buf[0x1a]);
   cln = (((buf[0x1b] & 0x0f) << 8) | buf[0x1a]);
   
   
   //printf("\nFirst cluster block in root: %d\n", cln);
   printf("First cluster block in root: %03X\n", cln);
   printf("First cluster block: %d\n", cln / 512);
   printf("First cluster id: %d\n", cln % 512); 
   printf("Cluster num from root block: %d\n", cln);
   unsigned short ofst = 0.4 + cln * 1.5;  //It's truncating not rounding...
   
   printf("Offset for FAT is: %d\n", ofst);
   //printf("Offset for FAT is: %d\n", ofstst);
   
   
   //Actual block number of cluster?:
   unsigned short lbn = hb + rb +nFAT*bpf + nRoot + (cln - 2)*bpc;
   //printf("\nFirst lbn data block in cluster is: %02X\n", lbn); 
   //printf("First lbn data block in cluster is: %c\n", lbn); 
   
   //while(cln < 0xFF8)
   //{
      pos = (firstFATLoc * 512) + (cln * 1.5);
      seekpos = lseek(fd, pos, SEEK_SET);   
      read(fd, buf2, 2);
      //printf("\nFirst FAT blocks after root is: %02X %02X\n", buf2[1], buf2[0]);
	  //printf("%d", (cln % 2));
      if(cln % 2 == 1)
      {	   
         cln = (buf2[1] << 4) | ((buf2[0]) >> 4);
      }
      else
      {
	      cln = (((buf2[1] & 0x0f) << 8) | buf2[0]);
	  }
	  
      lbn = hb + rb +nFAT*bpf + nRoot + (cln - 2)*bpc;
	  
      printf("\nFAT blocks are: %02X %02X\n", buf2[1], buf2[0]);
      printf("FAT cluster is: %03X\n", cln);   
      printf("Character from cluster: %c\n", cln);
      printf("lbn data block in cluster is: %02X\n", lbn); 
      printf("lbn data block in cluster is: %c\n", lbn);	  
	  
	  pos = (lbn - 2) * 512;  
	  seekpos = lseek(fd, pos, SEEK_SET);
	  
      numbytesread = read(fd, buf, 512);
	  
      printData(buf, numbytesread);
	  
	  numbytesread = read(fd, buf, 512);
	  
      printData(buf, numbytesread);
	  
	  numbytesread = read(fd, buf, 512);
	  
      printData(buf, numbytesread);
	  
   //}
   
   
   
   
   
   
    //=============================
   /*
   * Print out the root directory:
   */
   /*
   pos = rootLoc * 512;
   lseek(fd, pos, SEEK_SET);
   numbytesread = read(fd, buf, 512);
   printf("Printing root directory pg 0:\n");
   printBlock(buf, perline, numbytesread);
   
   
   
   
   //=======================
  /*
   * FAT information:
   */
   /*
   blocknum = firstFATLoc;
   pos = blocknum * 512;
   perline = 12;
   seekpos = lseek(fd, pos, SEEK_SET);
   printf("\nPrinting out FAT:\n");
   numbytesread = read(fd, buf, 512);
   printBlock(buf, perline, numbytesread);   
   
   numbytesread = read(fd, buf, 512);
   printBlock(buf, perline, numbytesread);
   
   
   numbytesread = read(fd, buf, 512);
   printBlock(buf, perline, numbytesread);   
   
   numbytesread = read(fd, buf, 512);
   printBlock(buf, perline, numbytesread);
   
   //for(int i = 1; i < nFAT; i++)
   //{
   //   printf("\nPrinting out FAT, pg %d:\n", i);
   //   numbytesread = read(fd, buf, 512);
   //   printBlock(buf, perline, numbytesread);
   //}
   
   
   
   //=====================
  /*
   * Image file data information:
   */
   //Last block and the bytes per block to find start of data:
   /*
   pos = (rootLoc + nRoot +1) * 512;
   perline = 12;
   seekpos = lseek(fd, pos, SEEK_SET);
   printf("\nPrinting out raw data:\n");
   
   numbytesread = read(fd, buf, 512);
   printBlock(buf, perline, numbytesread);
   
   //for(int i = 0; i < nblocks
   //{
   //   ;
   ///}
   
   */
   
   
} //END main
   
