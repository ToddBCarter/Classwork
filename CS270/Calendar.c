#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
   //int N = argc;
   //int *Jan;

   /*This now works in C, even tho it didn't then.
   So yeah.
   It even adds a null terminator at the end.
   DON'T FORGET THE NULL TERMINATOR DAMMIT*/
   char Jan[] = "January";
   char Feb[] = "February";
   char Mar[] = "March";
   char Apr[] = "April";
   char May[] = "May";
   char Jun[] = "June";
   char Jul[] = "July";
   char Aug[] = "August";
   char Sep[] = "September";
   char Oct[] = "October";
   char Nov[] = "November";
   char Dec[] = "December";

   struct Month {

   char *mon[];
   int days;
   int num;

   };

   struct *month Jan, Feb, Mar, Apr;

   


   //printf ("Test month: %s\n\n", Jan);

   //int *Jan = (int*)malloc(7*sizeof(int));
   //int *Feb = (int*)malloc(8*sizeof(int));
   //int *Mar = (int*)malloc(5*sizeof(int));





return 0;
}
