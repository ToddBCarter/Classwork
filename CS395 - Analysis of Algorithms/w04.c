/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out 1 2 3 4 5 6 etc.
 *
 * This is a simple program for Gaussian elimination
 * in a two dimensional matrix.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

void printMatrix(int n, float arr[n][n + 1]);

// 
// main() first converts the command line arguments into an array
// of floats, which is then turned into a two-dimensional array.
// This was done in two steps to stop atof() from causing problems.
// The first argument given is used as n.
//
int main(int argc, char* argv[])
{
   if(argc < 3)
   {
      printf("Usage %s 5 21 6/n",argv[0]);
      return 0;
   }

   int n = 0;
   float arrInp[argc - 1]; //arrInp is the array of command line arguments.
   int count = 1; //count keeps track of the argv[] index.

   //arrInp[0] is n when taken this way.
   for(int i = 0; i < argc - 1; i++)
   {
      arrInp[i] = atof(argv[i + 1]);
   }
   
   n = (int)arrInp[0];
   float arr[n][n + 1]; //Need to get n before declaring the array.

   //The input array is turned into the two dimensional array:
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < (n + 1); j++)
      {
         arr[i][j] = arrInp[count];
         count++;
      }
   }

   printMatrix(n, arr);
   float temp = 0;
   for(int i = 0; i <= (n - 2); i++)
   {
      for(int j = (i + 1); j <= (n - 1); j++)
      {
         temp = arr[j][i];
         for(int k = i; k <= n; k++)
         {
            arr[j][k] = arr[j][k] - (arr[i][k] * temp / arr[i][i]);
         }
      }
      printMatrix(n, arr);
   }
}

//
// The function to print a two dimensional array
// as a matrix where n = n and m = n + 1.
//
void printMatrix(int n, float arr[n][n + 1])
{
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < (n + 1); j++)
      {
         printf("%.2f ", arr[i][j]);
      }
      printf("\n");
   }
   printf("\n");

}