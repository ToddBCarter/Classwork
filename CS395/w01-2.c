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

//This is the modified MinDistance function.
//It uses the index of the first loop to 
//shorten the number of iterations of the second.
int MinDistance(int A[], int n)
{
   int dmin = INT_MAX;

   //use qsort with a compare that subtracts
   //She recommended setting j to i+1

   for(int i = 0; i < n; i++)
   {
      for(int j = i+1; j < n; j++)  //F(n) + 1?
      {
         if((abs(A[i] - A[j]) < dmin))
         {
            dmin = abs(A[i] - A[j]);
         }
      }
   }

   return dmin;
}
n-1		n-1
E		E			(1)
i=0		j = i + 1

(n -1) - (i + 1) + 1

n - i - 1

n-1
E		(n - i - 1)
i=0


n-1			n-1
E	(n-1) -	E	i
i=0			i=0


(n-1) ((n-1) - 0 + 1)


(n-1)(n) - (n(n-1))/2


(n-1) (n - n/2)


(n - 1)(n/2)


(n^2 - n)/2


/*

A(n) = A(n - 1) + A(n - 2) + 1

Guessing?

(A(n) + 1) = (A(n + 1) + 1) + (A(n - 2) + 1)  ??




*/