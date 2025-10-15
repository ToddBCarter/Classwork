/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A program that implements robot coin collection algorithm.
 *
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<math.h>
#include<string.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_SIZE 255

void RobotCoinCollection(int mx[MAX_SIZE][MAX_SIZE], int fx[MAX_SIZE][MAX_SIZE], int len, int m, int n);

////////////////////////////
//
// Main takes the components of the matrices.
//
int main(int argc, char* argv[]){
   if(argc < 3){
      printf("Insufficient arguments.\n");
   }

   int n = atoi(argv[1]); //rows
   int m = atoi(argv[2]); //cols

   int mx[MAX_SIZE][MAX_SIZE];
   int fx[MAX_SIZE][MAX_SIZE];

   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         //printf("test\n");
         if(argv[(i * m) + j + 3][0] == 'X'){
            mx[i][j] = -1;
         }else{
            mx[i][j] = atoi(argv[(i * m) + j + 3]);
         }
      }
   }

   printf("Board Inputed:\n");
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(mx[i][j] == -1){
            printf("X	");
         }else{
            printf("%d	", mx[i][j]);
         }
      }
      printf("\n");
   }
   printf("\n");

   RobotCoinCollection(mx, fx, argc - 3, m, n);

}

void RobotCoinCollection(int mx[MAX_SIZE][MAX_SIZE], int fx[MAX_SIZE][MAX_SIZE], int len, int m, int n){
   
   fx[1][1] = mx[1][1];

   for(int j = 1; j < m; j++){
      if(mx[0][j - 1] == -1){
         mx[0][j] = -1;
      }
      if(mx[0][j] == -1){
         fx[0][j] = 0;
      }else{
         fx[0][j] = fx[0][j - 1] + mx[0][j];
      }
   }

   for(int j = 1; j < n; j++){
      if(mx[j - 1][0] == -1){
         mx[j][0] = -1;
      }
      if(mx[j][0] == -1){
         fx[j][0] = 0;
      }else{
         fx[j][0] = fx[j - 1][0] + mx[j][0];
      }
   }

   for(int i = 1; i < n; i++){
      //fx[i][1] = fx[i - 1][1] + mx[i][1];
      for(int j = 1; j < m; j++){
         if(mx[i - 1][j] == -1 && mx[i][j - 1] == -1){
            mx[i][j] = -1;
         }
         if(mx[i][j] == -1){
            fx[i][j] = 0;
         }else{
            fx[i][j] = MAX(fx[i - 1][j], fx[i][j - 1]) + mx[i][j];
         }
      }
   }

   printf("Coin Collecting Table:\n");
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         printf("%d	", fx[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   printf("The optimal path with this board is: %d\n", fx[n - 1][m - 1]);
}