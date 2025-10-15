/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * This is a simple program to solve the Tower
 * of Hanoi puzzle.  The input to the program is
 * the number of disks in the original stack.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void towerOfHanoi(int n, char prev, char next, char side);

//
// main() for the program handles taking n from the command
// line and passing it to the function.
//
int main(int argc, char* argv[])
{
   if(argc < 2)
   {
      printf("Usage: ./a.out <#ofdisks>\n");
      return 0;
   }
   int n = atoi(argv[1]);

   towerOfHanoi(n, 'A', 'C', 'B');
}

//
// The Tower of Hanoi recursive algorithm.
// 'next' is the destination for the stack.
// 'prev' is the starting position of the stack.
//
void towerOfHanoi(int n, char prev, char next, char side)
{
   if (n == 0)
   {
      return;
   }
   n = n - 1;   
   towerOfHanoi(n, prev, side, next);
   printf("Move %c TO %c\n", prev, next);
   towerOfHanoi(n, side, next, prev);
}