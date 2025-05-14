/*A function meant to find the smallest value in the argument numberArray[].*/

#include<stdio.h>

#include"assignment_1_header_pt_3.h"

void minimumInArray(int numberArray[])
{
   int minimumValue = numberArray[0];  //minimumValue is first assigned to the 0th element.
   for (int i = 0; i < 5; i++)
   {	  
      minimumValue = numberArray[i] * (numberArray[i] < minimumValue) 
         + minimumValue * (numberArray[i] >= minimumValue);
   }
   printf("\nThe smallest value is: %d\n", minimumValue);
}