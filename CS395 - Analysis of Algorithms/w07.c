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
// 'dest' is the destination for the stack.
// 'home' is the starting position of the stack.
//
void towerOfHanoiRestricted(int n, char home, char side, char dest)
{
   if (n < 1)
   {      
      return;
   }
   towerOfHanoiRestricted(n - 1, home, side, dest);
   printf("Move %c TO %c\n", home, side);
   if(n > 1)
   {
      towerOfHanoiRestricted(n - 2, dest, home, side);
      printf("Move %c TO %c\n", dest, home);
      towerOfHanoiRestricted(n - 2, side, dest, home);
   }
   printf("Move %c TO %c\n", side, dest);
   towerOfHanoiRestricted(n-1, home, side, dest);
}