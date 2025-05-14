/*
CS 240
Assignment #5
Todd Carter
cart7982@vandals.uidaho.edu
3-19-2024
*/

/*
This is a simple program to multiply two matrices together 
while using multithreading.
The matrices are taken from a single file which is passed as 
an argument on the command line.  
The number of threads is also passed on the command line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Define the max array size:
#define MAX_SIZE 50

//Global variables for use by threads:
int rows_A, cols_A, cols_B;
float matrix_A[MAX_SIZE][MAX_SIZE];
float matrix_B[MAX_SIZE][MAX_SIZE];
float results[MAX_SIZE][MAX_SIZE];

//Struct used to store the indexes for first and last rows of matrix chunk:
typedef struct 
{
    int first_row;
    int last_row;
} ThreadChunk;

//Function to be given to threads:
//	- This function multiplies the two global matrices as arrays together.
void* multiplier(void* chunk) 
{
    ThreadChunk* current_chunk = (ThreadChunk*)chunk;

    for (int i = current_chunk->first_row; i < current_chunk->last_row; i++) 
	{
        for (int j = 0; j < cols_B; j++) 
		{
            results[i][j] = 0;
            for (int k = 0; k < cols_A; k++) 
			{
                results[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) 
{	
	int s = 0;  //Variable for error checking.
	
    FILE *file = fopen(argv[1], "r");

    int num_threads = atoi(argv[2]);
	
    if (num_threads < 1) 
	{
        printf("\nNumber of threads must be at least 1.\n");
        return 1;
    }

    fscanf(file, "%d %d %d", &rows_A, &cols_A, &cols_B);
	
	//printf("%d %d %d", rows_A, cols_A, cols_B);

    if (rows_A > MAX_SIZE || cols_A > MAX_SIZE || cols_B > MAX_SIZE) 
	{
        printf("Maximum matrix size exceeded.\n");
        return 1;
    }

    //Scan file for matrix A:
    for (int i = 0; i < rows_A; i++) 
	{
        for (int j = 0; j < cols_A; j++) 
		{
            fscanf(file, "%f", &matrix_A[i][j]);
			//printf("\n%f", matrix_A[i][j]);
        }
    }

    //Scan file for matrix B:
    for (int i = 0; i < cols_A; i++) 
	{
        for (int j = 0; j < cols_B; j++) 
		{
            fscanf(file, "%f", &matrix_B[i][j]);
        }
    }

    fclose(file);

	//Create number of threads as specified by command line:
    pthread_t threads[num_threads];
	
	//Declare the objects that store the start and end rows for each thread:
    ThreadChunk matrix_chunk[num_threads];

	//Calculate the number of rows per thread:
    int rows_per_thread = (rows_A + num_threads - 1) / num_threads;
	
	//This for loop loads the indexes of the first and last rows for each chunk:
    for (int i = 0; i < num_threads; i++) 
	{
        matrix_chunk[i].first_row = i * rows_per_thread;
        matrix_chunk[i].last_row = (i + 1) * rows_per_thread;
        
		//Check to prevent spillover:
		if (matrix_chunk[i].last_row > rows_A) 
		{
            matrix_chunk[i].last_row = rows_A;
        }

		//Create the threads:
        s = pthread_create(&threads[i], NULL, multiplier, (void*)&matrix_chunk[i]);
		if (s != 0)
		{
			printf("Error in thread creation.");
			return 1;
		}
    }

    //Join the threads:
    for (int i = 0; i < num_threads; i++) 
	{
        s = pthread_join(threads[i], NULL);
		if (s != 0)
		{
			printf("Error in thread joining.");
			return 1;
		}
    }

    //Print the resulting matrix just for something to do:
    printf("Results:\n");
    for (int i = 0; i < rows_A; i++) 
	{
        for (int j = 0; j < cols_B; j++) 
		{
            printf("%.2f ", results[i][j]);
        }
        printf("\n");
    }

    return 0;
}
