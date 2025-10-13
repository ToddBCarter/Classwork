/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A program that implments the Russian Peasant
 * style of multiplication.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<math.h>


////////////////////////////
//
// Main takes two arguments, converts to integers,
// then performs the operation.
//
int main(int argc, char* argv[]){
   if(argc != 3){
      printf("Insufficient arguments.\n");
   }
   int x = atoi(argv[1]);
   int y = atoi(argv[2]);
   int z = 0;
   int ans = 0;

   while(x > 0){
      if((x % 2) == 0){
         printf("%*d %*d\n", 6, x, 6, y);
         x = x / 2;
         y = y * 2;
      }else if((x % 2) == 1){
         z = y;
         printf("%*d %*d %*d\n", 6, x, 6, y, 6, z);
         x = x / 2;
         y = y * 2;
         ans = ans + z;
      }
   }
   printf("              ------\n");
   printf("%*d\n", 20, ans);
}