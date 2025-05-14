/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A program that implments QuickHull
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<math.h>
#include<string.h>


////////////////////////////
//
// Main takes two arguments, the pattern and the text,
// also know as the needle and the haystack.
//
int main(int argc, char* argv[]){
   if(argc != 3){
      printf("Insufficient arguments.\n");
   }

   //printf("argv1 is %s and 2 is %s\n", argv[1], argv[2]);

   int arr[argc];
   int arr2[];

   for(int i = 0; i < argc - 1; i++){
      arr[i] = atoi(argv[i]);
      //arr[i + 1] = atoi(argv[i]);
   }

   for(int i = 0; i < argc - 1; i++){
      for(int j = i; j < argc - 1; j++){
         



   //How do we determine the number of points to find?





   return 0;
}