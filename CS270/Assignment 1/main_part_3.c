/*CS270
Assignment 1
Todd Carter
cart7982@vandals.uidaho.edu
10-14-2023

This is the code for Part Three of the assignment.

This program loads up a simple array with a few numbers,
which is then given to four different functions.  The 
functions are: sum, average, find the minimum value, and 
find the maximum value.

Instead of being global, the array is local to main(),
and is passed as an argument to the four functions.
*/


#include<stdio.h>

#include"assignment_1_header_pt_3.h"

//extern char etext, ecomment;

int main (void)
{
   int numberArray[5] = { 8, 7, 6, 4, 9 };  //The same data from Parts 1 & 2 is used for the sake of comparison.

   sumArray(numberArray);
   averageArray(numberArray);
   minimumInArray(numberArray);
   maximumInArray(numberArray);

   return 0;
}


