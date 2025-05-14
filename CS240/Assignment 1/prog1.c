/*
CS 240 - Assignment 1
Todd Carter
cart7982@vandals.uidaho.edu
2-1-2024
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <delay duration> <iterations>\n", argv[0]);
		return 1;
	}
	
	int dura = atoi(argv[1]);
	int len = atoi(argv[2]);
	
	for (int i = 0; i < len; i++)
	{
		printf("Executing program: %s.\nProcess ID: %ld\nIteration number: %i\n\n", argv[0], (long)getppid(), (i+1));
		sleep(dura);
	}
	
	printf("Iterations complete, exiting program.\n\n");
	
	return 0;
}