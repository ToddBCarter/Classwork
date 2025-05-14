/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A program to compare several sorting algorithms,
 * selection sort, insertion sort, and quick sort.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<math.h>

void selectionSort(int arr[], int len);
void quickSort(int l, int r, int arr[], int len);
int HoarePartition(int l, int r, int arr[]); //partition for quickSort
void insertionSort(int arr[], int len);

////////////////////////////
//
// Main takes the number of entries for the first, smallest array,
// and then runs the comparison timing tests.
//
int main(int argc, char* argv[])
{
   srand(time(NULL));

   if(argc < 2){
      printf("Insufficient arguments\n");
   }
   int inp = atoi(argv[1]);

   //For precision, individual arrays and variables are used.
   int sarr1[inp]; //sarr means selection sort array
   int iarr1[inp]; //iarr means insertion sort array
   int qarr1[inp]; //qarr means quick sort array
   int sarr2[inp * 10];
   int iarr2[inp * 10];
   int qarr2[inp * 10];
   int sarr3[inp * 100];
   int iarr3[inp * 100];
   int qarr3[inp * 100];
   int newvalue = rand() % 10;
   struct timeval start, stop;
   double selectionTime[3]; //The times for the tests.
   double insertionTime[3];
   double quickTime[3];

   //
   // For each number of elements, the arrays are
   // loaded with the same random integers.  This
   // makes them each sort the same random numbers
   // without affecting the arrays for other tests.
   //
   for(int i = 0; i < inp; i++){
      sarr1[i] = newvalue;
      iarr1[i] = newvalue;
      qarr1[i] = newvalue;
      newvalue = rand() % 10;
   }
   for(int i = 0; i < (inp * 10); i++){
      sarr2[i] = newvalue;
      iarr2[i] = newvalue;
      qarr2[i] = newvalue;
      newvalue = rand() % 10;
   }
   for(int i = 0; i < (inp * 100); i++){
      sarr3[i] = newvalue;
      iarr3[i] = newvalue;
      qarr3[i] = newvalue;
      newvalue = rand() % 10;
   }


   //
   // The comparison tests.
   // They are organized by length of the array.
   // The first three are the smallest.
   // The next three are * 10, and the last three are * 100.
   //
   gettimeofday(&start, NULL);
   selectionSort(sarr1, inp);
   gettimeofday(&stop, NULL);
   selectionTime[0] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   insertionSort(iarr1, inp);
   gettimeofday(&stop, NULL);
   insertionTime[0] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   quickSort(0, inp - 1, qarr1, inp);
   gettimeofday(&stop, NULL);
   quickTime[0] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   selectionSort(sarr2, inp * 10);
   gettimeofday(&stop, NULL);
   selectionTime[1] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   insertionSort(iarr2, inp * 10);
   gettimeofday(&stop, NULL);
   insertionTime[1] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   quickSort(0, (inp * 10) - 1, qarr2, inp * 10);
   gettimeofday(&stop, NULL);
   quickTime[1] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   selectionSort(sarr3, inp * 100);
   gettimeofday(&stop, NULL);
   selectionTime[2] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   insertionSort(iarr3, inp * 100);
   gettimeofday(&stop, NULL);
   insertionTime[2] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   quickSort(0, (inp * 100) - 1, qarr3, inp * 100);
   gettimeofday(&stop, NULL);
   quickTime[2] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   //
   // Convert from milliseconds to seconds:
   //
   for(int i = 0; i < 3; i++){
      selectionTime[i] = selectionTime[i] * 1000;
      insertionTime[i] = insertionTime[i] * 1000;
      quickTime[i] = quickTime[i] * 1000;
   }

   printf("+------------------------------------------------+\n");
   printf("| Number of elements: %d\n", inp);
   printf("|   Selection sort time: %.1f sec\n", selectionTime[0]);
   printf("|   Insertion sort time: %.1f sec\n", insertionTime[0]);
   printf("|   Quick sort time: %.1f sec\n", quickTime[0]);
   printf("+------------------------------------------------+\n");
   printf("| Number of elements: %d\n", inp * 10);
   printf("|   Selection sort time: %.1f sec\n", selectionTime[1]);
   printf("|   Insertion sort time: %.1f sec\n", insertionTime[1]);
   printf("|   Quick sort time: %.1f sec\n", quickTime[1]);
   printf("+------------------------------------------------+\n");
   printf("| Number of elements: %d\n", inp * 100);
   printf("|   Selection sort time: %.1f sec\n", selectionTime[2]);
   printf("|   Insertion sort time: %.1f sec\n", insertionTime[2]);
   printf("|   Quick sort time: %.1f sec\n", quickTime[2]);
   printf("+------------------------------------------------+\n");
 
}

////////////////////////////
//
// selectionSort runs the sorting algorithm.
//
void selectionSort(int arr[], int len)
{
   int min = 0;
   int temp = 0;

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
   }
}


////////////////////////////
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
   }
}

//
// Hoare partition for finding the pivot point index for quickSort.
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

////////////////////////////
//
// Insertion sort algorithm.
//
void insertionSort(int arr[], int len)
{
   int v = 0;
   int j = 0;
   //printInsArray(arr, len, 0);
   for(int i = 1; i <= len - 1; i++){
      v = arr[i];
      j = i - 1;
      while(j >= 0 && arr[j] > v)
      {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = v;
   }
}

/*

CS395 $ ./a.out 1000
+------------------------------------------------+
| Number of elements: 1000
|   Selection sort time: 1565.0 sec
|   Insertion sort time: 806.0 sec
|   Quick sort time: 64.0 sec
+------------------------------------------------+
| Number of elements: 10000
|   Selection sort time: 145466.0 sec
|   Insertion sort time: 91210.0 sec
|   Quick sort time: 703.0 sec
+------------------------------------------------+
| Number of elements: 100000
|   Selection sort time: 14527113.0 sec
|   Insertion sort time: 7758787.0 sec
|   Quick sort time: 7648.0 sec
+------------------------------------------------+
CS395 $ ^C
CS395 $
CS395 $
CS395 $ ./a.out 1000
+------------------------------------------------+
| Number of elements: 1000
|   Selection sort time: 1500.0 sec
|   Insertion sort time: 808.0 sec
|   Quick sort time: 66.0 sec
+------------------------------------------------+
| Number of elements: 10000
|   Selection sort time: 145663.0 sec
|   Insertion sort time: 76161.0 sec
|   Quick sort time: 706.0 sec
+------------------------------------------------+
| Number of elements: 100000
|   Selection sort time: 14527841.0 sec
|   Insertion sort time: 7736902.0 sec
|   Quick sort time: 7735.0 sec
+------------------------------------------------+
CS395 $ ^C
CS395 $
CS395 $ ./a.out 1000
+------------------------------------------------+
| Number of elements: 1000
|   Selection sort time: 1487.0 sec
|   Insertion sort time: 782.0 sec
|   Quick sort time: 67.0 sec
+------------------------------------------------+
| Number of elements: 10000
|   Selection sort time: 145872.0 sec
|   Insertion sort time: 78504.0 sec
|   Quick sort time: 696.0 sec
+------------------------------------------------+
| Number of elements: 100000
|   Selection sort time: 14531123.0 sec
|   Insertion sort time: 7770646.0 sec
|   Quick sort time: 7672.0 sec
+------------------------------------------------+
CS395 $ ^C
CS395 $

*/