/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A program that implments Horspool's matching algorithm
 * for finding a string within a larger string.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<math.h>
#include<string.h>


void ShiftTable(char needle[], int table[], int m);
void HorspoolMatching(char needle[], char haystack[], int n, int m);
void printShiftTable(int table[]);

#define MAX_SIZE 256
#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

////////////////////////////
//
// Main takes two arguments, the pattern and the text,
// also know as the needle and the haystack.
//
int main(int argc, char* argv[]){
   if(argc != 3){
      printf("Insufficient arguments.\n");
   }

   printf("argv1 is %s and 2 is %s\n", argv[1], argv[2]);

   int m = strlen(argv[1]);
   int n = strlen(argv[2]);

   HorspoolMatching(argv[1], argv[2], n, m);

   return 0;
}

//
// Fills the shift table used by Horspool's and
// Boyer-Moore algorithm.
//
void ShiftTable(char needle[], int table[], int m){
   for(int i = 0; i < MAX_SIZE - 1; i++){
      table[i] = m;
   }
   for(int j = 0; j < (m - 1); j++){
      table[(int)needle[j]] = m - 1 - j;
   }
   printShiftTable(table);
}

//
// Horspool's algorithm for string matching
//
void HorspoolMatching(char needle[], char haystack[], int n, int m){
   int table[MAX_SIZE];

   int matches[MAX_SIZE];
   ShiftTable(needle, table, m);

   printf("%s\n", haystack);
   //int i = m - 1;
   int matchNum = 0;
   int k = 0;
   int shift = 0;
   for(int i = (m - 1); i <= (n - 1); i += shift){
      shift = 0;
      for(k = 0; k < m && (needle[m - 1 - k] == haystack[i - k]); k++);
 
      if(k == m){
         printf("%*s%s---found\n", i - m + 1,"", needle);
         matches[matchNum] = i - (m - 1);
         matchNum++;
         //i = i + table[(int)haystack[i]];  //Move to end of found pattern.
      }
      else{
         printf("%*s%s\n", i - m + 1, "", needle);
         //i++; //Increment one charater looking for next pattern.
      }
      shift = table[(int)haystack[i]];
   }
   printf("Matches found at locations:");
   for(int i = 0; i < matchNum; i++){
      printf(" %d", matches[i]);
   }
   printf("\n");

}

//
//Print out the shift table starting at the first writable character (space)
//
void printShiftTable(int table[])
{
   int i, start;
   for(start = MIN_WRITEABLE; start < MAX_ALPHABET; start+=TABLE_ROW_LENGTH)
   {
      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", table[i]);
      }
      printf("\n\n");

   }
}
