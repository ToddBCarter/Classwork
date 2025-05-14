/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A program that implments the Boyer Moore's matching algorithm
 * for finding a string within a larger string.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<math.h>
#include<string.h>

int match(char* needle, int m, int d1);

#define MAX_SIZE 256
#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

////////////////////////////
//
// Main takes two arguments, the pattern and the text,
// also know as the needle and the haystack.
//
int main(int argc, char* argv[]){
   if(argc != 3){
      printf("Insufficient arguments.\n");
   }


   int m = strlen(argv[1]);
   //int n = strlen(argv[2]);

   //BoyerMooreMatching(argv[1], argv[2], n, m);
   for(int i = 1; i < m; i++){
      int check = match(argv[1], m, i);
      printf("%d: %d\n", i, check);
   }


   return 0;
}


/////////////////
//  Forgot to turn the freaking thing in
//  Good shift table
//
int match(char* needle, int m, int d1){
   int shift = 1;
   int matches = 0;
   for(int i = (m - 2); i >= 0; i--){
      matches = 1;
      for(int j = 0; j < d1; j++){
         if((m - j - 1) >= 0 && (i - j) >= 0 && needle[i - j] != needle[m - j - 1]){
            matches = 0;
         }
      }
      if(matches && (((m - d1 - 1) < 0) || (i - d1) < 0 || (needle[i - d1] != needle[m - d1 - 1]))){
         return shift;
      }
      shift++;

   }
   return m;
}