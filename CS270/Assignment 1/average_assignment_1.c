/*A function to average the values in the global array numberArray.*/

#include<stdio.h>

#include"assignment_1_header.h"

void averageArray(void)
{
   int averageTotal = 0;  //averageTotal is used to first add the values, then divide them.
   for (int i = 0; i < 5; i++)
   {
      averageTotal = averageTotal + numberArray[i];
   }
   printf("\nThe average of the array is: %d\n", averageTotal/5);
}