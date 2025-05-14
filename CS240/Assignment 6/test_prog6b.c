#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char **argv)
{
	char fname[50]; // Holds disk image file name
	int fd; // UNIX file descriptor
	int numbytesread; // actual no of bytes read from file
	unsigned char buf[5120]; // character buffer
	int pos, seekpos; // pos = desired byte position, seekpos = actual
	int blocknum; // block number to seek to
	int perline = 32; // number of values (bytes printed per line
	unsigned short int val; // holds int value of two bytes
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
	blocknum = 0;
	pos = blocknum * 512;
	seekpos = lseek(fd, pos, SEEK_SET);
	printf("Seekpos is %d\n\n", seekpos);
		
	/*
	* Headings for table
	*/
	printf("StartByte|\n");
	for(j = perline -1; j >= 0; j--)
		printf("%3d ", j);
		printf(" |\n");
		printf(" Dec Hex |\n");
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
	while(!numbytesread)
	{
		numbytesread = read(fd, buf, 512);
		printf("Read %d bytes from file\n\n", numbytesread);
		for(i = 0; i < numbytesread; i+=perline)
		{
			printf("%4d %03X |", i, i);  //Prints out the 0 000
			//This shows what line it is, I guess...
			for(j = i + perline - 1; j >= i; j--)  //Starts 16 bits in
				printf(" %02X ", buf[j]);  //Print out hex numbers, maybe entry table?
				printf( " |\n |");  //Line break
			for(j = i + perline - 1; j >= i; j--)
			{
				if(buf[j] < 32 || buf[j] > 126)
					printf(" . ");  //Print out a dot if it's outside range to be a character.
				else
					printf(" %c ",buf[j]);  //Print out the character if found.
									//Seems to include name and stuff?  There's like random junk in the buffer...
			} // END for j
			printf( " |\n |");
			
	/*		for(j = i + perline - 1; j >= i; j-=2)
			{
				val = buf[j] << 8 | buf[j-1];  //???
				printf(" %5d ", val); //This only cals the 16 bit value, not useful
			}*/
			//printf(" |\n\n");
			
		} // END for i
	}
	printf("\n");
} //END main