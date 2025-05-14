/*A function to find the largest value in the array.*/

#include<stdio.h>

#include"assignment_1_header.h"

void maximumInArray(void)
{
   int maximumValue = numberArray[0];  //maximumValue is first assigned to the 0th element.
   for (int i = 0; i < 5; i++)
   {
      maximumValue = numberArray[i] * (numberArray[i] > maximumValue) 
         + maximumValue * (numberArray[i] <= maximumValue);
   }
   printf("\nThe largest value in the array is: %d\n", maximumValue);
}