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
void tokenize(char*, int);

//
// This is main.  It dictates and handles the file to be used
// for data by the tokenizer and lexer.
//
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


//
// This is the lexer function.
// It handles removing spaces and preparing the tokens as strings.
//
void lex(char * line, int length, int start, int end, char * type, int remove_spaces)
{
   char token[MAXTOKEN];
   while (remove_spaces && start < length && isspace(line[start]))
   {
      start++;
   }

   if(start > end)
   {
      return;
   }
   strncpy(token, &line[start], (end - start + 1));
   token[end - start + 1] = '\0';
   printf("%s: %s\n", type, token);
}

// 
// This is the tokenizer.
// It checks for special characters to section out the line
// that is taken from the file.  This is then provided to
// the lex function, which breaks the line into strings.
//
void tokenize(char* line, int length)
{
   int end = 0;
   int start = 0;
   int temp = 0;
   //static int comm = 0;
   //int count = 0;

   for (end = 0; end < length; end++)
   {
      //count++;
      if(line[end] == '*'  && end > 3 && ((length - 4) > 0)
      {
         temp = end - 3;
         lex(line, length, temp, temp + 7, "Star Thing: ", 1);
      }
      else if (isspace(line[end]))
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
      }
   }
   return;
} 