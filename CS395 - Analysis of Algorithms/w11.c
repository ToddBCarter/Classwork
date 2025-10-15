/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A simple program to 
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int len);
void printArray(int arr[], int len, int loc);

//
// Main handles taking input from command line.
//
int main(int argc, char* argv[])
{
   if(argc < 2){
      printf("Array already sorted.\n");
   }

   int arrInp[argc - 1];

   for(int i = 0; i < argc - 1; i++){
      arrInp[i] = atoi(argv[i + 1]);
   }

   insertionSort(arrInp, argc - 1);
}

//
// insertion sort algorithm.
//
void insertionSort(int arr[], int len)
{
   int v = 0;
   int j = 0;
   printArray(arr, len, 0);
   for(int i = 1; i <= len - 1; i++){
      v = arr[i];
      j = i - 1;
      while(j >= 0 && arr[j] > v)
      {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = v;
      //printf("%d\n", i);
      printArray(arr, len, i);
   }
}


//
// printArray prints out the array.
//
void printArray(int arr[], int len, int loc)
{
   for(int i = 0; i < len; i++){
      printf("%d", arr[i]);
      printf(" ");
      if(i == loc){
         printf("| ");
      }
   }
   printf("\n");
}