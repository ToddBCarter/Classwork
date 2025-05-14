/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * This is a basic tokenizer program that checks
if a token is empty before printing it.  strlen()
is used for the check.
 *********************************************/

#define MAXTOKEN 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void lexer(char*, int);
int tokenize(char*, int);

//This is main.  It dictates and handles the file to be used
//for data by the tokenizer and lexer.
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
   if (fp == NULL) 
   {
      printf("Error: Could not open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }
   while ((read = getline(&line, &len, fp)) != -1) 
   {
      tokenize(line, read);
   }
   fclose(fp);
   if (line) 
   {
      free(line);
   }
   exit(EXIT_SUCCESS);
}

// This is the tokenizer.
// It prints out the line into a token one character at a time, 
// while ignoring spaces and turning double quoted sections into
// strings, then prints.
int tokenize(char* line, int length)
{
   int end = 0;
   char token[MAXTOKEN];
   int check = 0; //check keeps track of the character being added to the token
   int quotes = 0; //quotes keeps track of whether the token is enclosed by quotes or not

   for (end = 0; end <= length; end++)
   {
      char current = line[end];
      if (current == '"')
      {
         if(check > 0 && quotes == 0)
         {
            token[check] = '\0';
            printf("Token: %s\n", token);
            check = 0;
         }
         token[check] = '"'; //Add in doublequotes to the string token.
         check++;
         quotes = !quotes;
         if(!quotes)
         {
            token[check] = '\0'; //Null terminating so it can be printed as a string.
            printf("String: %s\n", token);
            check = 0;
         }
      }
      else if (isspace(current) && quotes == 0)
      {
         if(check > 0) //This means the token has characters in it.
         {
            token[check] = '\0';
            printf("Token: %s\n", token);
            check = 0;
         }
      }
      else
      {
         token[check] = current;
         check++;
      }
      
   }
   return 0;
}