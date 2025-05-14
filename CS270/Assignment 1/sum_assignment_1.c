/*A simple summation function for the global array, numberArray.*/

#include<stdio.h>

#include"assignment_1_header.h"

void sumArray(void)
{
   int sumTotal = 0;  //sumTotal is used to add up the array values.
   for (int i = 0; i < 5; i++)
   {
      sumTotal += numberArray[i];
   }
   printf("\nThe sum of the array is: %d\n", sumTotal);
}
