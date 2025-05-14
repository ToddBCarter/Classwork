/*CS270
Assignment 1
Todd Carter
cart7982@vandals.uidaho.edu
10-14-2023

This program loads up a simple global array with a few numbers,
which are then put through four different functions.  The 
functions are: sum, average, find the minimum value, and 
find the maximum value.
*/


#include<stdio.h>

#include"assignment_1_header.h"

int numberArray[5] = { 8, 7, 6, 4, 9 };  //Barebones storage into a global array.

int main (void)
{
   sumArray();
   averageArray();
   minimumInArray();
   maximumInArray();

   return 0;
}


