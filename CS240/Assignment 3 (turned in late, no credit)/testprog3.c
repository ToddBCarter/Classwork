#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char filename[256];
    char **lines = NULL;
    FILE *file;

    // Prompt for the input file name
    printf("Enter the name of the text file: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove the newline character

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    size_t lineCount = 0;
	
	//Concatenate the lines from the file into a single string:
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove the newline character at the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Allocate memory for the new line
        lines = realloc(lines, (lineCount + 1) * sizeof(char *));
        if (lines == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        // Allocate memory for the line content
        lines[lineCount] = malloc(strlen(line) + 1);
        if (lines[lineCount] == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        // Copy the line content to the allocated memory
        strcpy(lines[lineCount], line);

        lineCount++;
    }
	
	
	

    // Print each line as a token
    printf("Lines as tokens:\n");
    for (size_t i = 0; i < lineCount; i++) {
        printf("Token %lu: %s\n", i + 1, lines[i]);
        free(lines[i]); // Free memory for each line
    }

    // Free memory for the array of pointers
    free(lines);

    fclose(file);

    return 0;
}
