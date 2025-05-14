/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * This is a simple program to find the 
 * shortest distance amount between any two 
 * integers of an array.
 *
 *********************************************/

#define MAXSIZE 256

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int MinDistance(int A[], int n);

//Main for the assignment.
//It takes arguments from the command line and
//converts them into an array, which is then
//passed to the MinDistance function.
//The size of the array is also calculated and
//passed.
int main(int argc, char* argv[])
{
   int arr[argc - 1];
   int dmin = 0, n = 0;
   if(argc < 3)
   {
      printf("Usage %s 5 21 6/n",argv[0]);
      return 0;
   }

   for(int i = 0; i <= (argc - 2); i++)
   {
      arr[i] = atoi(argv[i + 1]);
   }

   n = sizeof(arr)/sizeof(arr[0]);

   dmin = MinDistance(arr, n);

   printf("dmin is: %d\n\n", dmin);
}

//This is the MinDistance function.
//It takes n^2 iterations to find the smallest
//distance between any two entries of the array.
int MinDistance(int A[], int n)
{
   int dmin = INT_MAX;

   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < n; j++)
      {
         if((i != j) && (abs(A[i] - A[j]) < dmin))
         {
            dmin = abs(A[i] - A[j]);
         }
      }
   }
   return dmin;
}