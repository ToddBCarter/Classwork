
/*Test program as copied from provided example.
To compile:
	gcc testHello.c hello.c

To run:
	./a.out Bruce Dog1 Cat2 aardvark

Expected output:

Hello Bruce
Hello Dog1
Hello Cat2
Hello aardvark

Bruce Bolden
March 19, 2020
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"hello.h"

int main(int argc, char *argv[])
{
   int x = 10;
   int y = 255;
   char test[y];
   printf("Welcome to the game.  It is a gamelike game.  Here we go.\n\n");
   printf("Would you like to play the game?");
   printf("Please enter Y or N and hit enter.");
   fgets (test, sizeof(test), stdin);
   //scanf("%s", test);
   printf("Test is: %s\n\n", test);
   
   
   for(int i = 1; i < argc; i++)
   {
      printf("i is currently: %i\n", i);
	  //printf("%s, 
      //SayHello(argv[i]);
	  //system("clear");  //This method of clearing only in stdlib
      //printf("system: clear\n"); //not sure if this actually worked, but maybe
   }
   
   return 0;
}
