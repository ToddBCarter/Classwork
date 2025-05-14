/*
CS 240
Assignment 3
Todd Carter
2-27-2024 (very late)

As this assignment is being turned in late,
no credit is expected.  This is for the sake
of completion and for study.
Thank you for your patience.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_LINE_LENGTH 256

void executeCommand(char *command);

int main(int argc, char *argv[]) {	
    char filename[256];
    char **lines = NULL;
    FILE *file;
	
	char line[MAX_LINE_LENGTH];
    size_t lineCount = 0;
	
    if (argc != 2) {
        printf("Usage: %s <max_processes>\n", argv[0]);
        return 1;
    }

    int maxProcesses = atoi(argv[1]);

    if (maxProcesses <= 0) {
        printf("Invalid value for max_processes.\n");
        return 1;
    }

    //Prompt for the input file name
    printf("Enter the name of the data file: ");
    fgets(filename, MAX_LINE_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0'; //Remove the newline character

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("fopen");
        return 1;
    }
	

	//This while loop is a modified version of Assignment 2.
	//This tokenizes the file so the tokens can then be used.
    while (fgets(line, sizeof(line), file) != NULL) {
        //Remove the newline character at the end of the line
        line[strcspn(line, "\n")] = '\0';

        //Allocate memory for the new line
        lines = realloc(lines, (lineCount + 1) * sizeof(char *));
        if (lines == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        //Allocate memory for the line content
        lines[lineCount] = malloc(strlen(line) + 1);
        if (lines[lineCount] == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        //Copy the line content to the allocated memory
        strcpy(lines[lineCount], line);

        lineCount++;
    }		
	
	//Limiter for maximum processes.
    int runningProcesses = 0;
	
	//This for loop steps through the array of tokens and uses each one, rather than
	//causing an infinite loop of madness.
	for (int i = 0; i < lineCount; i++)
	{
		pid_t pid;

        //Execute command if not empty and the maximum number of processes was not reached
        if (strlen(lines[i]) > 0 && runningProcesses < maxProcesses) {
            // Prefix the command with "./" to execute it with a bash shell
            char fullCommand[MAX_COMMAND_LENGTH + 3];
            snprintf(fullCommand, sizeof(fullCommand), "./%s", lines[i]);

            // Fork a new process
            pid = fork();

            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (pid == 0) {
                // Child process
                executeCommand(fullCommand);
                exit(EXIT_SUCCESS);
            }

            runningProcesses++;
        }

        //Wait for a child process to complete if the maximum number of processes was reached
        if (runningProcesses == maxProcesses) {
            if (wait(NULL) > 0) {
                runningProcesses--;
            }
        }
	}

    fclose(file);

    //Wait for all remaining child processes to complete
    while (runningProcesses > 0) {
        if (wait(NULL) > 0) {
            runningProcesses--;
        }
    }

    return 0;
}

void executeCommand(char *command) {
    printf("Executing command: %s\n", command);
    system(command);
}
