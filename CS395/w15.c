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


void ShiftTable(char needle[], int table[], int m);
//void GoodSuffixTable(char needle[], int gsuffix[], int m);
void GoodSuffixTable(int* gsuffix, char* needle, int m);
int match(char* needle, int m, int d1);
void BoyerMooreMatching(char needle[], char haystack[], int n, int m);
void printShiftTable(int table[]);

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

   //printf("argv1 is %s and 2 is %s\n", argv[1], argv[2]);

   int m = strlen(argv[1]);
   int n = strlen(argv[2]);

   BoyerMooreMatching(argv[1], argv[2], n, m);

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
// Good shift matching
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


//
// Good shift table for Boyer-Moore algorithm.
//
void GoodSuffixTable(int* gsuffix, char* needle, int m){
   //int index = m;
   //int len = 0;
   //char* suff;
   //char suff;
   //char pattern[MAX_SIZE];
   //int check = 0;

   for(int i = 1; i < m; i++){
      int check = match(needle, m, i);
      gsuffix[i] = check;
   }

   for(int i = 1; i < m; i++){
      printf("%d %*s %d\n", i, m, &needle[m - i], gsuffix[i]);
   }
}


//
// Boyer-Moore algorithm for string matching
//
void BoyerMooreMatching(char needle[], char haystack[], int n, int m){
   int table[MAX_SIZE];
   int matches[MAX_SIZE];
   int gsuffix[MAX_SIZE];
   int matchNum = 0;
   int k = 0;
   int shift = 0;
   int d1, d2;
   static int flag = 0;
   //int tmp[m + 1];

   ShiftTable(needle, table, m);

   //Initialize the gsuffix table to 0
   for(int i = 0; i < m + 1; i++){
      gsuffix[i] = 0;
   }

   GoodSuffixTable(gsuffix, needle, m);

   //for(int i = 1; i < m; i++){
   //   printf("testing %d %*s %d\n", i, m, &needle[m - i], gsuffix[i]);
   //}

   printf("%s\n", haystack);

   for(int i = (m - 1); i <= (n - 1); i += shift){
      shift = 0;
      shift = table[(int)haystack[i]];
      for(k = 0; k < m && (needle[m - 1 - k] == haystack[i - k]); k++);

      d1 = MAX((table[(int)haystack[k]] - k), 1);
      d2 = (int)gsuffix[k];

      //printf("d1 %d d2 %d\n", d1, d2);

      if(k == 0){
         shift = d1;
      }
      if(m > k && k > 0){
         shift = MAX(d1, d2);
      }
      if(k == m){
         printf("%*s%s---found\n", i - m + 1,"", needle);
         matches[matchNum] = i - (m - 1);
         matchNum++;
         shift = 1;
      }
      else{
         if(d1 > 0 && d2 > 0){
            printf("%*s%s d1=%d d2=%d\n", i - m + 1, "", needle, d1, d2);
            flag = 0;
         }
         else if((d1 <= 0 || d2 <= 0) && flag == 0){
            printf("%*s%s\n", i - m + 1, "", needle);
            flag = 1;
         }
            
         //i++; //Increment one charater looking for next pattern.
      }
      //shift = table[(int)haystack[i]];
      //if(d1 > 0 || d2 > 0){
      //   printf("%*s%s\n", i - m + 1, "", needle);
      //}
         
         
         
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