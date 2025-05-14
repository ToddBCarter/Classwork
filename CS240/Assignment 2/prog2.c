/*
CS 240 - Assignment 2
Todd Carter
cart7982@vandals.uidaho.edu
2-11-2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototype required by assignment:
int makearg(char *s, char ***args);

/*
main() takes arguments from the command line
of the network unix system, concatenates them into a single
temporary string, and then provides that string to makearg(),
which tokenizes them.

makearg() then returns the number of arguments, and a 
numbered list of those arguments as tokens.

token_array is used to store the individual tokens.
temp_string is used to capture the concatenated arguments.
*/
int main(int argc, char *argv[])
{   
   char **token_array = NULL;
   int token_count, i;
   int temp_len = 0;
   
   //Brief instruction manual.
   if (argc < 2)
   {
	   printf("\nUsage of makearg():\n  $ %s string to be tokenized\n\n", argv[0]);
	   return -1;
   }
   
   //Get the length of temporary array in order to allocate memory.
   for (i = 1; i < argc; i++)
   {
	   temp_len += strlen(argv[i])+1;
   }
   
   //Declare and initialize the temporary string.
   char *temp_string = (char *)malloc(temp_len + 1);
   temp_string[0] = '\0';
   
   //Concatenate the arguments from the command line into the temp string.
   for (i = 1; i < argc; i++)
   {
      strcat(temp_string, argv[i]);
      if (i < argc - 1)
	  {
         strcat(temp_string, " ");
	  }
   }	  

   token_count = makearg(temp_string, &token_array);
   
   //Check if an error was returned while allocating memory.
   if (token_count == -1)
   {
	   printf("Encountered a memory error!\n");
	   return -1;
   }

   printf("Number of tokens: %d\n", token_count);
   printf("Tokens:\n");
   for (i = 0; i < token_count; i++)
   {
      printf("Token %d: %s\n", i + 1, token_array[i]);
   }

   //Free up memory after use.
   for (i = 0; i < token_count; i++)
   {
      free(token_array[i]);
   }
   free(token_array);
   free(temp_string);

   return 0;
}

/*
  The function makearg() in this case uses strtok() to tokenize 
  the string produced by concatenating the arguments from the command line.  
  The tokens are then copied into the same pointer array that is token_array in main.
*/
int makearg(char *s, char ***args) 
{
   char *token;
   char *delimiter = " ";
   int token_count = 0;

   *args = (char **)malloc(sizeof(char *));
   
   //Check for memory.
   if (*args == NULL)
   {
      return -1;
   }   
	   
   token = strtok(s, delimiter);
   
   /*This while loop handles adjusting the size of the
   args token array and copying over the tokens.*/
   while (token != NULL)
   {
      //Resize the array with realloc.
      *args = (char **)realloc(*args, (token_count + 1) * sizeof(char *));
	  
      if (*args == NULL)
      {
         return -1;
      }

      //Allocate memory for the args token array.
      (*args)[token_count] = (char *)malloc(strlen(token) + 1);
	  
      if ((*args)[token_count] == NULL)
      {
         return -1;
      }
	  
	  //Copy over the token into the array.
      strcpy((*args)[token_count], token);

      token_count++;
	  
	  //Empty out token for the next loop.
      token = strtok(NULL, delimiter);
   }

   return token_count;
}