//
//  main.c
//  UNIX_Shell
//
//  Created by Lauren Coseo on 3/30/22.
//

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void) {
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    int should_run = 1; /* flag to determine when to exit program */
    while (should_run) {
        printf("osh>");
        fflush(stdout);

        // size_t getline(char **lineptr, size_t *n, FILE *stream);

        int bytes_read;
        int size = 20;
        char *string;

        /* These 2 lines are very important. */
        string = (char *) malloc (size);
        bytes_read = getline (&string, &size, stdin);

        if (bytes_read == -1) {
            // puts ("ERROR!");
        }

        // getline - get line from terminal
        // strtok - tokenize the string into the args char array

        const char s[2] = " ";
        char *token;

        /* get the first token */
        token = strtok(str, s);

        /* walk through other tokens */
        while( token != NULL ) {
            printf( " %s\n", token );
            token = strtok(NULL, s);
        }

        //* After reading user input, the steps are:
        //* (1) fork a child process using fork()
        //* (2) the child process will invoke execvp()
        //* (3) parent will invoke wait() unless command included & */

        // if exit is typed, should_run = 0
        should_run = 0;
    }

    return 0;
}
