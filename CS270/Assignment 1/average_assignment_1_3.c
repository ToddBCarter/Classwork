/*A function to average the values in the argument numberArray.*/

#include<stdio.h>

#include"assignment_1_header_pt_3.h"

void averageArray(int numberArray[])
{
   int averageTotal = 0;  //averageTotal is used to first add the values, then divide them.
   for (int i = 0; i < 5; i++)
   {
      averageTotal = averageTotal + numberArray[i];
   }
   printf("\nThe average of the array is: %d\n", averageTotal/5);
}