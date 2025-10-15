/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A simple program to take a integers from the
 * command line, put them into an array, then
 * use selection sort to sort the array.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

void selectionSort(int arr[], int len);
void printArray(int arr[], int len);

// 
// main() handles taking the command line arguments
// and converting them into an integer array
//
int main(int argc, char* argv[])
{
   if(argc < 2)
   {
      printf("Insufficient arguments.\n");
   }

   int arrInp[argc - 1];

   for(int i = 0; i < argc - 1; i++)
   {
      arrInp[i] = atoi(argv[i + 1]);
   }

   selectionSort(arrInp, (argc - 1));
}

//
// printArray prints out the array.
//
void printArray(int arr[], int len)
{
   for(int i = 0; i < len; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

//
// selectionSort runs the sorting algorithm.
//
void selectionSort(int arr[], int len)
{
   int min = 0;
   int temp = 0;
   printArray(arr, len);

   for(int i = 0; i < len - 1; i++)
   {
      min = i;
      for(int j = i + 1; j < len; j++)
      {
         if(arr[j] < arr[min])
         {
            min = j;
         }
      }
      temp = arr[i];  //Swap the values
      arr[i] = arr[min];
      arr[min] = temp;
      temp = 0;
      printArray(arr, len);
   }
}