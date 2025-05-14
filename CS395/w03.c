/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * This is a simple, inefficient program to
 * to find 2^n using recursion, as requested.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

int bruteForce(int n);

//main() converts the argument from the command line
//into an integer and passes that to the recursive
//function.
int main(int argc, char* argv[])
{
   int n = atoi(argv[1]);   

   int output = bruteForce(n);

   printf("%d\n",output);
}

//The recurisve function, based on
// 2^n = 2^(n-1) + 2^(n-1)
int bruteForce(int n)
{
   if (n == 0)
   {
      return 1;
   }
   else
   {
      return bruteForce(n - 1) + bruteForce(n - 1);
   }
}