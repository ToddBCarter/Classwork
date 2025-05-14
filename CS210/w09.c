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
#define MAXKEYWORD 35

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
// It handles removing spaces and preparing the tokens as strings for printing.
//
void lex(char * line, int length, int start, int end, char * type, int remove_spaces)
{
   char token[MAXTOKEN]; 
   char* keywords[MAXKEYWORD] = {"accessor", "and", "array", "bool", "case", "character", "constant", "else", "elsif", "end", "exit", "float", "func", "if", "ifc", "in", "integer", "is", "mutator", "natural", "null", "of", "or", "others", "out", "pkg", "positive", "proc", "ptr", "range", "subtype", "then", "type", "when", "while"};
   int isKeyword = 0;
   int isNumLit = 0;
   int isIdentifier = 0;
   int count = 0;
   int check = 0;

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

   // Check if it is a Keyword:
   for(int i = 0; i < MAXKEYWORD; i++)
   {
      if((strncmp(token, keywords[i], strlen(keywords[i])) == 0) && (strlen(token) == strlen(keywords[i])))
      {
         isKeyword = 1;
      }        
   }

   // Check if it is a Numeric Literal:
   if(isxdigit(token[0]) != 0)
   {
      count = 0;
      check = 0;
      for(int i = 0; i < strlen(token); i++)
      {
         if(token[i] == '.')
         {
            count++;
         }
         if(isxdigit(token[i]) == 0 && token[i] != '.')
         {
            check = 1;
         }
      }
      if(count < 2 && check != 1)
      {
         isNumLit = 1;
      }
   }

   // Check if it is an Identifier:
   if(isalpha(token[0]) != 0)
   {
      count = 0;
      for(int i = 0; i < strlen(token); i++)
      {
         if(isalpha(token[i]) == 0 && isdigit(token[i]) == 0 && token[i] != '_')
         {
            count++;
         }
      }
      if(count < 1)
      {
         isIdentifier = 1;
      }
   }


   if(isKeyword == 1)
   {
      printf("Keyword: %s\n", token);
      isKeyword = 0;
   }
   else if(isNumLit == 1)
   {
      printf("Numeric: %s\n", token);
      isNumLit = 0;
   }
   else if(isIdentifier == 1)
   {
      printf("Identifier: %s\n", token);
      isIdentifier = 0;
   }
   else
   {
      printf("%s: %s\n", type, token);
   }
}

// 
// This is the tokenizer.
// It checks the line input one character a time for constructing into string tokens.
//
void tokenize(char* line, int length)
{
   int end = 0;
   int start = 0;
   static int comm = 0;

   for (end = 0; end <= length; end++)
   {
      if (comm || (line[end] == '/' && line[end+1] == '*'))
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
         end++;
         while(end < length - 1 && (line[end] != '/' || line[end-1] != '*'))
         {
            end++;
         }
         if(line[end] != '/' || line[end-1] != '*')
         {
            lex(line, length, start, end - 1, "Comment", 1 - comm);
            comm = 1;
            return;
         }
         lex(line, length, start, end, "Comment", 1 - comm);
         comm = 0;
         start = end + 1;
      }

      else if (line[end] == '"')
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
         end++;
         while(line[end] != '"')
         {
            end++;
         }
         lex(line, length, start, end, "String", 1);
         start = end + 1;
      }

      else if (line[end] == '\'')
      {
         lex(line, length, start, end-1, "Token", 1);
         start = end;
         end++;
         if(line[end] == '\\')
         {
            end++;
         }
         end++;
         lex(line, length, start, end, "Char", 1);
         start = end + 1;
      }

      else if (line[end] == '<')
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
         //end++;
         if(line[end + 1] == '<' || line[end + 1] == '>' || line[end + 1] == '=')
         {
            end++;
         }
         //end++;
         lex(line, length, start, end, "Operator", 1);
         start = end + 1;
      }

      else if (line[end] == '>')
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
         if(line[end + 1] == '>' || line[end + 1] == '=')
         {
            end++;
         }
         lex(line, length, start, end, "Operator", 1);
         start = end + 1;
      }

      else if (line[end] == '[' || line[end] == ']' || line[end] == '(' || line[end] == ')' || line[end] == '+' || line[end] == '-' || line[end] == '/' || line[end] == '|' || line[end] == '&' || line[end] == ';' || line[end] == ',' || line[end] == '$' || line[end] == '@')
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
         lex(line, length, start, end, "Operator", 1);
         start = end + 1;
      }

      else if (line[end] == '*')
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
         if(line[end + 1] == '*')
         {
            end++;
         }
         lex(line, length, start, end, "Operator", 1);
         start = end + 1;
      }

      else if (line[end] == ':')
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
         if(line[end + 1] == '=')
         {
            end++;
         }
         lex(line, length, start, end, "Operator", 1);
         start = end + 1;
      }

      else if (line[end] == '=')
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
         if(line[end + 1] == '>')
         {
            end++;
         }
         lex(line, length, start, end, "Operator", 1);
         start = end + 1;
      }

      else if (line[end] == '{' || line[end] == '}')
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
         if(line[end + 1] == ':')
         {
            end++;
         }
         lex(line, length, start, end, "Operator", 1);
         start = end + 1;
      }

      else if ((line[end] == '!' && line[end + 1] == '=') || (line[end] == '.' && line[end + 1] == '.'))
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
         end++;
         lex(line, length, start, end, "Operator", 1);
         start = end + 1;
      }

      else if (isspace(line[end]))
      {
         lex(line, length, start, end - 1, "Token", 1);
         start = end;
      }

   }
   return;
} 