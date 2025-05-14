/*
CS 240
Assignment 4
Todd Carter
cart7982@vandals.uidaho.edu
2-27-2024
*/

/*
This is a simplified shell program that takes inputs from the user,
tokenizes them and uses them to find the PATH from the system,
and uses it to run system commands with execv().
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1000
#define MAX_TOKENS 100

//Linked list node struct for containing shell variables:
typedef struct variableNode {
    char *name;
    char *value;
    struct variableNode *next;
} variableNode;

//Function to load the list with variable names and associated values:
void addVar(variableNode **head, char *name, char *value) {
    variableNode *new_node = (variableNode *)malloc(sizeof(variableNode));
    new_node->name = strdup(name);
    new_node->value = strdup(value);
    new_node->next = *head;
    *head = new_node;
}

//Function to retrieve values from the list,
//as decided in main(), using the name of the
//variable associated with the value:
char *getValue(variableNode *head, char *name) {
    variableNode *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

/*
Prototypes for the parsing function and the command function.
 - The parser breaks the user input into tokens which are stored in array tokens[].
	- The parser additionally checks for a & indicating a background process.
 - The command function forks the program and runs execv.
*/
void parser(char *input, char *tokens[], int *background);
void runCommand(char *tokens[], int background, variableNode *variable);

int main()
{	
	char input[MAX_LENGTH];    //Takes user input. 
	char *tokens[MAX_TOKENS];  //Stores tokenized input.
	int background = 0;	//Flag for if process is in the background.
	
	variableNode *variable = NULL;	//Head of the linked list.	
	
	//While loop that handles the program:
	while(1)
	{
		printf("$ ");
		fflush(stdout);
		
		if(fgets(input, MAX_LENGTH, stdin) == NULL)
		{
			break;
		}
		
		input[strcspn(input, "\n")] = '\0';
		
		//If there is no input, repeat the loop.
		if (strlen(input) == 0)
		{
			continue;
		}		
		
		//First, check for an '=' to see if a variable is being created.
		//If found, it tokenizes either side and adds to the linked list.
		if (strchr(input, '='))
		{
			char *token1, *token2;
			
			token1 = strtok(input, "=");			
			token2 = strtok(NULL, "=");
			
			//Add the tokens to the linked list:
			addVar(&variable, token1, token2);
		}		
		else
		{			
			//Run the parser function to tokenize input entirely:
			parser(input, tokens, &background);
			
			if (strcmp(tokens[0], "quit") == 0)
			{
				//Close the shell on "quit".
				break;
			}
			else
			{
				//Check for a '$' symbol.  If a token taken from input has one in the
				//correct position, the token is replaced with the value held in the
				//linked list.
				for (int i = 0; tokens[i] != NULL; i++)
				{
					if (tokens[i][0] == '$')
					{
						char *var_name = tokens[i] + 1;  //+1 to skip $
						
						//Retrieve the value from the linked list:
						char *var_value = getValue(variable, var_name);
						if (var_value != NULL)
						{
							tokens[i] = var_value;  //Overwrite the value if it's a variable.
						}
					}
				}
				//The modified array of tokens is then handed to the command function.
				runCommand(tokens, background, variable);
			}
		}
	}
	
	variableNode *current_var = variable;
	while (current_var != NULL)
	{
		variableNode *next_var = current_var->next;
		free(current_var->name);
		free(current_var->value);
		free(current_var);
		current_var = next_var;
	}
	
	printf("Exiting shell.\n");
	return 0;	
}

/*
This function forks the program and creates a child using execv.
If the background variable has been flipped, then it will move on with the program.
*/
void runCommand(char *tokens[], int background, variableNode *variables) 
{
    pid_t pid = fork();

    if (pid < 0) 
	{
        printf("Fork error");
        exit(EXIT_FAILURE);
    } 
	else if (pid == 0) 
	{
        //Get the PATH variable string from the environment:
        char *path = getenv("PATH");
		
		if (path == NULL) 
		{
			printf("Unable to get PATH variable");
			exit(EXIT_FAILURE);
		}

		//Construct the file path for execv by tokenizing the PATH:
        char *path_token = strtok(path, ":");
        while (path_token != NULL) 
		{
            char full_path[MAX_LENGTH];
			
            snprintf(full_path, sizeof(full_path), "%s/%s", path_token, tokens[0]);

			//Creating the child process with execv:
			if (execv(full_path, tokens) != -1)
			{
                exit(EXIT_SUCCESS);
            }
            path_token = strtok(NULL, ":");
        }

        //If no executable is found, the loop breaks and an error is printed:
        printf("Command not found: %s\n", tokens[0]);
        exit(EXIT_FAILURE);
    } 
	else 
	{
        if (!background) 
		{
            //If not a background process, wait for the child to complete:
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

/*
This function tokenizes the input string.
In addition to tokenizing the string,
it also checks for the & symbol that marks a
background process.
*/ 
void parser(char *input, char *tokens[], int *background)
{
	int token_count = 0;
	
	//Take the first string out to the delimiters:
	char *token = strtok(input, " \t\n");
	
	//Loop through remaining input:
	while (token != NULL)
	{
		tokens[token_count++] = token;
		token = strtok(NULL, " \t\n");
	}
	
	//Check for background process:
	if (token_count > 0 && strcmp(tokens[token_count - 1], "&") == 0)
	{
		//Set pointer to indicate background process
		*background = 1;
		//Remove & symbol
		tokens[token_count - 1] = NULL;
	}
	else
	{
		*background = 0;
	}
	
	tokens[token_count] = NULL;	
}