/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * Simple program that applies a brute force
 * algorithm to find index locations of a string
 * within a larger string.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int bruteForceStringMatch(char* T, char* P);

//main() converts the argument from the command line
//into an integer and passes that to the brute force.
int main(int argc, char* argv[])
{
   if (argc < 2)
   {
      printf("Insufficient input: %s.\n", argv[0]);
   }

   char* P = argv[1];
   char* T = argv[2];

   bruteForceStringMatch(T, P);
}

//A brute force algorithm for finding index locations
//of specific string codes in larger strings.
int bruteForceStringMatch(char* T, char* P)
{
   int n = strlen(T);
   int m = strlen(P);
   printf("Matches found at locations:");
   for (int i = 0; i <= (n - m); i++)
   {
      int j = 0;
      while(j < m && P[j] == T[i + j])
      {
         j++;
      }
      if(j == m)
      {
         printf(" %i", i);
         //return i;  //This is the print?
      }
   }
   printf("\n");
   return -1;
}