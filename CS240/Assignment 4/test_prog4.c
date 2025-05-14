#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;  // Declaration for environ

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

// Node structure for a linked list to store variable assignments
typedef struct VariableNode {
    char *name;
    char *value;
    struct VariableNode *next;
} VariableNode;

// Function to add a variable to the linked list
void add_variable(VariableNode **head, char *name, char *value) {
    VariableNode *new_node = (VariableNode *)malloc(sizeof(VariableNode));
    new_node->name = strdup(name);
    new_node->value = strdup(value);
    new_node->next = *head;
    *head = new_node;
}

// Function to get the value of a variable from the linked list
char *get_variable(VariableNode *head, char *name) {
    VariableNode *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void execute_command(char *tokens[], int background, VariableNode *variables) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process

        // Get the PATH variable
        char *path = getenv("PATH");
        if (path == NULL) {
            perror("Unable to get PATH variable");
            exit(EXIT_FAILURE);
        }

        // Create a new environment array including variables
        int env_size = 0;
        while (environ[env_size] != NULL) {
            env_size++;
        }

        char *new_env[env_size + 2];
        for (int i = 0; i < env_size; i++) {
            new_env[i] = environ[i];
        }

        // Add user-defined variables to the environment
        VariableNode *current_var = variables;
        while (current_var != NULL) {
            char *env_variable = (char *)malloc(strlen(current_var->name) + strlen(current_var->value) + 2);
            sprintf(env_variable, "%s=%s", current_var->name, current_var->value);
            new_env[env_size++] = env_variable;
            current_var = current_var->next;
        }

        new_env[env_size] = NULL; // Null-terminate the array
		
		//for (int i = 0; i < env_size+2; i++)
		//{
		//	printf("\nnew env is: %s", new_env[i]);
		//}

        char *path_token = strtok(path, ":");
        while (path_token != NULL) {
            // Construct the full path to the executable
            char full_path[MAX_INPUT_SIZE];
            snprintf(full_path, sizeof(full_path), "%s/%s", path_token, tokens[0]);

            // Try to execute the command
            //char **exec_tokens = tokens + 1; // Skip the command name in tokens
            if (execve(full_path, tokens, new_env) != -1) {
                // If successful, break the loop
				//printf("Test");
                exit(EXIT_SUCCESS);
            }

            path_token = strtok(NULL, ":");
        }

        // If no executable is found, print an error message
        fprintf(stderr, "Command not found: %s\n", tokens[0]);
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        if (!background) {
            // If not a background process, wait for the child to complete
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

void parse_input(char *input, char *tokens[], int *background) {
    int token_count = 0;
    char *token = strtok(input, " \t\n");

    while (token != NULL) {
        tokens[token_count++] = token;
        token = strtok(NULL, " \t\n");
    }

    // Check if the last token is "&" for background execution
    if (token_count > 0 && strcmp(tokens[token_count - 1], "&") == 0) {
        *background = 1;
        tokens[token_count - 1] = NULL; // Remove "&" from tokens
    } else {
        *background = 0;
    }

    tokens[token_count] = NULL; // Null-terminate the array
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_TOKENS];
    int background;

    // Linked list to store variable assignments
    VariableNode *variables = NULL;

    while (1) {
        printf("$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit on Ctrl+D
        }

        // Remove newline character at the end
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            continue; // Empty input, prompt again
        }

        // Check for variable assignment
        if (strchr(input, '=')) {
            char *var_name = strtok(input, "=");
            char *var_value = strtok(NULL, "=");
            add_variable(&variables, var_name, var_value);
        } else {
            // Regular command execution
            parse_input(input, tokens, &background);

            if (strcmp(tokens[0], "exit") == 0) {
                break; // Exit the shell
            } else {
                // Replace variables with their values in the command tokens
                for (int i = 0; tokens[i] != NULL; i++) {
                    if (tokens[i][0] == '$') {
                        // Variable substitution
                        char *var_name = tokens[i] + 1; // Skip the '$'
                        char *var_value = get_variable(variables, var_name);
                        if (var_value != NULL) {
                            tokens[i] = var_value;
                        }
                    }
                }

                // Execute the command
                execute_command(tokens, background, variables);
            }
        }
    }

    // Free allocated memory for variables
    VariableNode *current_var = variables;
    while (current_var != NULL) {
        VariableNode *next_var = current_var->next;
        free(current_var->name);
        free(current_var->value);
        free(current_var);
        current_var = next_var;
    }

    printf("Exiting uish shell\n");
    return 0;
}
