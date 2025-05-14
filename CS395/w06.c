/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * This is a modified version of the Tower
 * of Hanoi puzzle.  The input to the program is
 * the number of disks in the original stack.
 *
 * In this version, no disc is allowed to move
 * from A to C or C to A, and instead must first
 * be placed on B before moving onward.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void towerOfHanoiRestricted(int n, char prev, char next, char side);

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

   towerOfHanoiRestricted(n, 'A', 'B', 'C');
}

//
// The Tower of Hanoi recursive algorithm.
// 'next' is the destination for the stack.
// 'prev' is the starting position of the stack.
//
void towerOfHanoiRestricted(int n, char home, char side, char dest)
{
   if (n == 0)
   {      
      return;
   }
   n = n - 1;   
   towerOfHanoiRestricted(n, home, side, dest);
   printf("Move %c TO %c\n", home, side);
   towerOfHanoiRestricted(n, dest, side, home);
   printf("Move %c TO %c\n", side, dest);
   towerOfHanoiRestricted(n, home, side, dest);
}