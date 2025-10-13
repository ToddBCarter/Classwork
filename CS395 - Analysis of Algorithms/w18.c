/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A program that implements an exhaustive search
 * to uncover shared vertices between graphs.
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
// Main takes the components of the matrices.
//
int main(int argc, char* argv[]){
   if(argc < 3){
      printf("Insufficient arguments.\n");
   }

   int n = atoi(argv[1]); //first line of the triangle
   int len = (n * (n - 1)) / 2; //length of upper triangle

   int triangle[len];
   for(int i = 0; i < len; i++){
      triangle[i] = atoi(argv[i + 2]);
   }

   


