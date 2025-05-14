/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A recursive program for printing out all
 * possible permutations of 1 to n of a 
 * given integer.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

void permute(int arr[], int start, int end);
void swap(int* A, int* B);
void printArray(int arr[], int len);

//
// main handles taking the command line
// argument for n and converting to int.
//
int main(int argc, char* argv[])
{
   if(argc < 2)
   {
      printf("Usage:  ./a.out n  \n");
   }
   int n = atoi(argv[1]);

   int arr[n];

   for(int i = 1; i <= n; i++)
   {
      arr[i - 1] = i;
   }

   permute(arr, 0, n - 1);
}

//
// printArray prints out the array.
//
void printArray(int arr[], int len)
{
   for(int i = 0; i < len; i++)
   {
      printf("%d", arr[i]);
   }
   printf("\n");
}

//
// Function to swap two members of the array.
//
void swap(int* A, int* B)
{
   int temp = *A;
   *A = *B;
   *B = temp;
}

//
// permute() uses a swapping recursion to
// move through the possible permutations.
// The speed function (maybe) comes out to:
//     F(n + 1) + 2
//
void permute(int arr[], int start, int end)
{
   //int temp;
   if(start == end)
   {
      printArray(arr, end + 1);
      return;
   }
   for(int i = start; i <= end; i++)
   {
      /*
      temp = arr[start];  //First swap adds +1
      arr[start] = arr[i];
      arr[i] = temp;
      temp = 0;
      */
      swap(&arr[start], &arr[i]);

      permute(arr, start + 1, end);  //Recursion F(n + 1)

      swap(&arr[start], &arr[i]);
      /*
      temp = arr[start];  //Second swap adds +1
      arr[start] = arr[i];
      arr[i] = temp;
      temp = 0;
      */
   }
}