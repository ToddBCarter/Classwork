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

void quickSort(int l, int r, int arr[], int len);
int HoarePartition(int l, int r, int arr[]);
void swap(int* a, int* b);
void printSubArray(int l, int r, int arr[], int len);

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

   quickSort(0, argc - 2, arrInp, argc - 1);
   printSubArray(0, argc - 2, arrInp, argc - 1);
}

//
// Quick sort algorithm using out put from HoarePartition.
//
void quickSort(int l, int r, int arr[], int len)
{
   int s = 0;
   if(l < r){
      s = HoarePartition(l, r, arr);
      quickSort(l, s - 1, arr, len);
      quickSort(s + 1, r, arr, len);
      printSubArray(l, r, arr, len);
   }
}

//
// Hoare partition for finding the pivot point index.
//
int HoarePartition(int l, int r, int arr[])
{
   int p = arr[l];
   int i = l;
   int j = r + 1;
   int temp = 0;

   do{
      do{
         i++;
      }while(arr[i] < p);

      do{
         j = j - 1;
      }while(arr[j] > p);

      //swap(&arr[i], &arr[j]);
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      temp = 0;
   }while(i < j);

   //swap(&arr[i], &arr[j]);
   temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
   temp = 0;

   //swap(&arr[l], &arr[j]);
   temp = arr[l];
   arr[l] = arr[j];
   arr[j] = temp;
   temp = 0;

   return j;

}

//
// Swap by reference for two positions in array.
// Does not work due to bad alloc
//
void swap(int* a, int* b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

//
// printArray prints out the array.
//
void printSubArray(int l, int r, int arr[], int len)
{
   //printf("%i\n", l);
   //printf("%i\n", r);

   for(int i = 0; i < len; i++){
      if(i == l){
         printf("[");
      }
      printf("%d", arr[i]);
      if(i == r){
         printf("] ");
      }
      printf(" ");
   }
   printf("\n");
}