/*********************************************
 * Id: cart7982
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * This is a tokenizer program that takes an
 * input file and breaks the plain text into
 * tokens, strings, character literals, and
 * comments.
 *
 *********************************************/

#define MAXTOKEN 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void lexer(char*, int);
int tokenize(char*, int);
/*
 This is main.  It dictates and handles the file to be used
 for data by the tokenizer and lexer.
*/
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

/* 
 This is the tokenizer.
 It prints out the line into a token one character at a time, 
 while ignoring spaces and turning double quoted sections into
 strings, then prints.
*/
int tokenize(char* line, int length)
{
   int end = 0;
   char token[MAXTOKEN];
   int check = 0; //check keeps track of the character being added to the token
   int quotes = 0; //quotes keeps track of whether the token is enclosed by quotes or not
   int s_quote = 0;
   static int comm = 0;

   //Maybe turn this into a while loop
   for (end = 0; end <= length; end++)
   {
      char current = line[end];
      if (current == '"' && comm == 0 && s_quote == 0)
      {
         if(check > 0 && quotes == 0)
         {
            //If there is already a token, print it.
            token[check] = '\0';
            printf("Quote Token: %s\n", token);
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

      else if (current == '\'' && quotes == 0 && comm == 0)
      {
         if(check > 0 && s_quote == 0)
         {
            //If there is already a token, print it.
            token[check] = '\0';
            printf("Character literal Token: %s\n", token);
            check = 0;
         }
         token[check] = '\''; //Add in a single quote to the string token.
         check++;
         s_quote = !s_quote;
         if(!s_quote)
         {
            token[check] = '\0'; //Null terminating so it can be printed as a string.
            printf("Character literal: %s\n", token);
            check = 0;
         }
      }

      else if (current == '/' && quotes == 0 && s_quote == 0)
      {
         //check for backslash, unless preceded by a backslash
         //check for backslash unless followed by asterisk
         //printf("test\n");
         if (line[end + 1] == '*' && comm == 0)
         {
            //all of the same stuff again
            //but using comm instead of s_quote
            //printf("test2\n");
            if(check > 0 && comm == 0)
            {
               //If there is already a token, print it.
               token[check] = '\0';
               printf("Comm Token: %s\n", token);
               check = 0;
            }
            token[check] = '/'; //Add in a slash.
            check++;
            //printf("test3 comm is: %i\n", comm);
            comm = 1; //Flip the flag.
            //printf("test3 comm is: %i\n", comm);
         }
         else if (line[end - 1] == '*' && comm == 1)
         {
            token[check] = '/'; //Add in a slash.
            check++;
            if(check > 0)
            {
               token[check] = '\0'; //Null terminating so it can be printed as a string.
               printf("Comment: %s\n", token);
               check = 0;
            }
            comm = 0;
         }
         else
         {
            token[check] = current;
            check++;
         }
      }

      else if (isspace(current) && quotes == 0 && s_quote == 0 && comm == 0)
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
         //printf("comm is: %i\n", comm);
         //This needs to ignore the newline during comments
         //how is the question
         //if (token[check] == '\n')
         //{
         //   check++;
         //}
         token[check] = current;
         check++;
      }
      
   }
   return 0;
}