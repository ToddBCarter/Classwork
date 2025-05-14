/*
CS240
Assignment 6
Todd Carter
cart7982@vandals.uidaho.edu
4-2-2024
*/


/*
This is a simple program that takes a floppy disk image file that
uses the FAT12 system and does two things:

   - Prints all file entries in root out with name, extension,
     time and date of file creation, file size, and the starting
	 cluster block number for the file.
	 
   - Prints contents of the README file.
   
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/*
   Functions from handouts:
*/
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
   Function to print out the file information from the root directory.
   The root directory is read through 32 bytes at a time until the last
   entry, which allows these locations to be re-used.
*/
void rootInformation(unsigned char buf[])
{
   unsigned int timeCre = makeint(buf,0x16);
   unsigned int dateCre = makeint(buf, 0x18);
   if(buf[0] != 0) //Check if entry is empty
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

	   printf("Time created: %02d:%02d:%02d\n", hour, minute, second);
	   
	   int day = dateCre & 0x1F;
	   int month = (dateCre >> 5) & 0x0F;
	   int year = ((dateCre >> 9) & 0x7F) + 1980;
	   
	   printf("Date created: %02d:%02d:%02d\n", day, month, year);
   }
}//End of rootInformation()


/*
   Function to print out the data from a data block as ASCII characters.
   It is used to print out the README file.
*/
void printData(unsigned char buf[], int numbytesread)
{
	int perline = 20;
	for(int j = 0; j < (numbytesread/perline)+1; j++)
      {
	     for(int i = j * perline; i < ((j * perline) + perline); i++)
	     {
	        printf("%c", buf[i]);
	     }
	     printf("\n");
      }
}//End of printData()


/*
Some of this is just a modified version of the dumpfile.
*/
int main(int argc, char **argv)
  {
   char fname[50];          // Holds disk image file name
   int fd;                  // UNIX file descriptor
   unsigned char buf[5120]; // character buffer
   int numbytesread;        // actual no of bytes read from file
   int pos;                 // pos = desired byte position
   int blocknum;            // block number to seek to
   int perline = 16;        // number of values (bytes printed per line
   unsigned short int val;  // holds int value of two bytes
   
   unsigned int bpb, rb, nerd, nblocks, bpf, hb;
   unsigned char bpc, nFAT;
   
   unsigned int nRoot;       // Numnber of blocks in root directory
   
   int i,j;
   unsigned short cln;      // cluster number taken from root   
   unsigned char buf2[3];   // holds bytes from cluster   
   unsigned short lbn;      // block number for current data block   
   
   unsigned int firstFATLoc;//Alternate first FAT block location.
   unsigned int rootLoc;    //Alternate first root block.
   
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
   lseek(fd, pos, SEEK_SET);
   numbytesread = read(fd, buf, 512);
  
 /*
  * Parameters extracted from boot block,
  * taken from assignment materials:
  */

   bpb = makeint(buf,0x0b);     // Bytes per block
   bpc = buf[0x0d];             // Blocks per cluster
   rb = makeint(buf,0x0e);      // Reserved blocks
   nFAT = buf[0x10];            // Number of FATs
   nerd = makeint(buf,0x11);    // Number of root directory entries
   nblocks = makeint(buf,0x13); // Number of blocks on disk
   bpf = makeint(buf,0x16);     // Number of blocks per FAT
   hb = makeint(buf,0x1c);      // Number of hissen blocks

   nRoot = (nerd*32 + bpb)/ bpb;
   
   
   //======================================
  /*
   * Root block information:
   */ 
   
   //Alternate ways of calculating these parameters:
   firstFATLoc = rb + hb;
   rootLoc = firstFATLoc + (nFAT * bpf);   
   
   //Print out each file name and information from root: 
   pos = rootLoc * 512;
   lseek(fd, pos, SEEK_SET);
   numbytesread = read(fd, buf, 32);
   rootInformation(buf);
   
   i = 1;
   while(i < nerd)
   { 
      read(fd, buf, 32);
      rootInformation(buf);
	  i++;
   }
   
   
   //=============================
  /*
   * Use root information to retrieve data:
   */ 
   
   //Changing i changes which file is used, and 11 = README:
   i = 11;
   pos = (rootLoc * 512) + (32 * i);
   lseek(fd, pos, SEEK_SET);
   read(fd, buf, 32);
   
   printf("\nFile being used is: \n");
   rootInformation(buf);
   
   //Attempt to get cluster from first blocks of root:
   printf("\nRoot cluster numbers are: %02X %02X\n\n", buf[0x1b], buf[0x1a]);
   cln = (((buf[0x1b] & 0x0f) << 8) | buf[0x1a]);
   
   //Seek out first cluster bytes:
   pos = (firstFATLoc * 512) + (cln * 1.5);
   lseek(fd, pos, SEEK_SET);   
   read(fd, buf2, 2);
   
   //Modulus to differentiate which bytes to slice:
   if(cln % 2 == 1)
   {	   
	  cln = (buf2[1] << 4) | ((buf2[0]) >> 4);
   }
   else
   {
 	  cln = (((buf2[1] & 0x0f) << 8) | buf2[0]);
   }
  
   //Number of first data block:
   lbn = hb + rb +nFAT*bpf + nRoot + (cln - 2)*bpc;
   
   //Seek to location of first data block:
   pos = (lbn - 2) * 512;  
   lseek(fd, pos, SEEK_SET);
   numbytesread = read(fd, buf, 512);  
   printData(buf, numbytesread);
   
   //Step through blocks with read() to print the
   //rest of the message, per the assignment:
   numbytesread = read(fd, buf, 512);  
   printData(buf, numbytesread);
  
   numbytesread = read(fd, buf, 512);  
   printData(buf, numbytesread);  
   
} //END main
   
