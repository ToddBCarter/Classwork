#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char** argv)
{
   int testNum[7] = {1, 2, 3, 4, 5, 6, 7};
   int N = 9;
   int a = 9;

   //int *pA;   //First declare the label variable
   int *pA = (int *)malloc(N*sizeof(int));  //Allocate the memory for string

   //sprintf(*pA, "%d", a);

   pA[0] = 12;


   printf("Here goes nothing: %i\n", pA[0]);



   //struct  Node;
   //{
   //   int Data;
   //   struct Node* next;
   //}

   //struct Node* NodePtr;

   //NodePtr head = NULL;


   //printf("




   FILE *fp;
   FILE *PFRaces;
   FILE *PFSkills;
   FILE *PFSpells;

   fp = fopen("/CS270/PFClasses.txt", "w");
   if (fp == NULL)
   {
      printf ("Unable to open: %s\n", "/CS270/PFClasses.txt");
      return 0;
   }

   

   //printf ("Printing the string: %s\n", Q);


   fclose(fp);

return 0;

}
