/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * This is a basic tokenizer program that checks
 * if a token is empty before printing it.  strlen()
 * is used for the check.
 *********************************************/

#define MAXTOKEN 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int tokenize(char*, int);

//It should be noted that using /**/ instead of // results in an compiler error.

//This is main.  It dictates and handles the file to be used
//for data by the tokenizer.
int main(int argc, char* argv[])
{
   if (argc < 2)
   {
      printf("Please specify input file.\n");
      printf("%s /y/shared/Engineering/cs-drbc/assignments/cs210/x01_in1.txt\n", argv[0]);
      return 1;
   }
   FILE* fp;
   char* line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen(argv[1], "r");
   if (fp == NULL) {
      printf("Error: Could not open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }
   while ((read = getline(&line, &len, fp)) != -1) {
      tokenize(line, read);
   }
   fclose(fp);
   if (line) {
      free(line);
   }
   exit(EXIT_SUCCESS);
}

//This is the tokenizer.  It uses strlen to check if a token 
//is larger or equal to one, which indicates that there is a
//character present instead of a whitespace.  If a token contains
//only whitespace, it will move on without printing.
int tokenize(char* line, int length)
{
   int start = 0;
   int end = 0;
   char token[MAXTOKEN];
   int check = 0;
   for (end = 0; end <= length; end++)
   {
      if (isspace(line[end]))
      {					
         snprintf(token, (end - start + 1), &line[start]); 
         check = strlen(token);
         if (check > 0)
         {
            printf("Token: %s\n", token);
            start = (end + 1);
         }
         else
         {
            start = end + 1;
         }	
      }
   }
   return 0;
}