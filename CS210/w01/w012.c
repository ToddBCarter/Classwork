#define MAXTOKEN 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

    // Assign meaning to tokens
    //void lex(char *line, int start, int end);

    // Break the string down into tokens
    //int tokenize(char *line, int length);


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

int tokenize(char* line, int length)
{
    int start = 0;
    int end = 0;
    char token[MAXTOKEN];  //Already defined earlier in code.
    for (end = 0; end <= length; end++)
    {

	int test = isspace(line[end]);  //It is not printing out other error codes.  Is there a way to make it do so?
	printf("Test is: %i\n", test);
	
	if (isspace(line[end]))
        {
            snprintf(token, (end - start + 1), &line[start]);   //only copy over a certian number of chars to another destination.
            printf("Token: %s\n", token);
            start = (end + 1);
	}
    }

    //printf("%s\n", line);  //Print the line as a string.
    return 0;
}