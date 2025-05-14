/*A function meant to find the smallest value in the global array.*/

#include<stdio.h>

#include"assignment_1_header.h"

void minimumInArray(void)
{
   int minimumValue = numberArray[0];  //minimumValue is first assigned to the 0th element.
   for (int i = 0; i < 5; i++)
   {	  
      minimumValue = numberArray[i] * (numberArray[i] < minimumValue) 
         + minimumValue * (numberArray[i] >= minimumValue);
   }
   printf("\nThe smallest value is: %d\n", minimumValue);   
}