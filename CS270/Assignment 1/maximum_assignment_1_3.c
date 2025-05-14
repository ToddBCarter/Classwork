/*A function to find the largest value in the argument numberArray.*/

#include<stdio.h>

#include"assignment_1_header_pt_3.h"

void maximumInArray(int numberArray[])
{
   int maximumValue = numberArray[0];  //maximumValue is first assigned to the 0th element.
   for (int i = 0; i < 5; i++)
   {
      maximumValue = numberArray[i] * (numberArray[i] > maximumValue) 
         + maximumValue * (numberArray[i] <= maximumValue);
   }
   printf("\nThe largest value in the array is: %d\n", maximumValue);
}