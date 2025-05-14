/*main.c*/

#include<stdio.h>
#include<stdlib.h> /*malloc*/

#include"sum.h"

int Sum( int* A, int* B, int n );
void Add( int* A, int* B, int* C, int n );

//int *A;
//int *B;

int main(int argc, char *argv[])
{
   int n = 3;
   int A[3] = {0,1,1};
   int B[3] = {1,0,0};
   int C[3] = {0,0,0};
   int sum;
   //Each argument inputted is a pointer in the array, so each name, ie
   //


   //A = (int *)malloc(3*sizeof(int));
   //B = (int *)malloc(3*sizeof(int));

   //A = {0,1,1};

   sum = Sum(A, B, n);
   //Add ( A, B, C, n );
   printf("The sum: %d\n", sum);

   //free( A );
   //free (B);

   return 0;
}
