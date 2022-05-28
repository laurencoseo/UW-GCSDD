//
//  shell.c
//  DIY UNIX_Shell
//
//  Created by Lauren Coseo on 3/30/22.
//

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>   // for open
#include <unistd.h>  // for close
#include <stdbool.h> // for bool
#include <sys/wait.h>  //for wait

#define MAX_LINE 80             // The maximum length command

// Executes a command with no special characters
void executeNormally(char **args) {
    int status;
    int waitPid;
    int pid = fork();
    
    if (pid < 0) {
        printf("Error: Fork Failure\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(args[0], args);
        printf("Error executing command\n");
        exit(EXIT_FAILURE);
    } else {
        waitPid = wait(&status);
        if (waitPid == -1)
        {
            printf("Error on Wait\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Executes a command with an input redirection
void executeWithInput(char **args, int i) {
    int status;
    int waitPid;
    int pid = fork();
    
    if (pid < 0) {
        printf("Error: Fork Failure\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {      // child
        int fd = open(args[i+1], O_RDONLY);
        
        if (fd < 0) {
            printf("Failure to open input file\n");
            exit(EXIT_FAILURE);
        } else {
            dup2(fd, STDIN_FILENO);        // dup to stdin
            execvp(args[0], args);
            printf("Error executing command\n");
            exit(EXIT_FAILURE);
        }
    } else {                    // parent
        waitPid = wait(&status);
        if (waitPid == -1)
        {
            printf("Error on Wait\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Executes a command with an output redirection
void executeWithOutput(char **args, int i) {
    int status;
    int waitPid;
    int pid = fork();
    
    if (pid < 0) {
        printf("Error: Fork Failure\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {      // child
        int fd = open(args[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd < 0) {
            printf("Failure to open output file\n");
            exit(EXIT_FAILURE);
        } else {                // parent
            dup2(fd, STDOUT_FILENO);        // dup to stdout
            execvp(args[0], args);
            printf("Error executing command\n");
            exit(EXIT_FAILURE);
        }
    } else {
        waitPid = wait(&status);
        if (waitPid == -1)
        {
            printf("Error on Wait\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Executes a command with a pipe
void executeWithPipe(char **args, int i) {
    enum {READ, WRITE};
    int pid1, pid2;

    int pipeFD[2];                      // create pipe

    if (pipe(pipeFD) < 0)
    {
       printf("Error in creating pipe\n");
       exit(EXIT_FAILURE);
    }
    
    pid1 = fork();
    
    if (pid1 < 0) {
        printf("Error: Fork Failure\n");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {         // child 1 --------------------------
        // Closing read side of pipe which is not used
        close(pipeFD[READ]);
        dup2(pipeFD[WRITE], STDOUT_FILENO);
        close(pipeFD[WRITE]);
        execvp(args[0], args);
        printf("Error executing command\n");
        exit(EXIT_FAILURE);
    }
    
    pid2 = fork();
    
    if (pid2 < 0) {
        printf("Error: Fork Failure\n");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {        // child 2 ---------------------
        // Closing write side of pipe which is not used
        close(pipeFD[WRITE]);
        dup2(pipeFD[READ], STDIN_FILENO);
        close(pipeFD[READ]);
        
        execvp(args[i+1], &args[i+1]);
        printf("Error executing command\n");
        exit(EXIT_FAILURE);
    }
    
    // parent --------------------------
    close(pipeFD[READ]);
    close(pipeFD[WRITE]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

// Executes a command with &
void executeWithoutWait(char **args) {
    int pid = fork();
    
    if (pid < 0) {
        printf("Error: Fork Failure\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(args[0], args);
        printf("Error executing command\n");
        exit(EXIT_FAILURE);
    } else {
        return;
    }
}

// Reads a command and determines what type of command it is
void runCommand(char **args) {
    // specify which command is given
    int jobType = 0;
    int arg_count = 0;
    
    while (args[arg_count] != NULL) {
        
        /* --------------  INPUT REDIRECT ------------------ */
        if (strcmp(args[arg_count], "<") == 0) {
            args[arg_count] = NULL;
            jobType = 1;
            break;
        }
        
        /* --------------  OUTPUT REDIRECT ----------------- */
        else if (strcmp(args[arg_count], ">") == 0) {
            args[arg_count] = NULL;
            jobType = 2;
            break;
        }
        
        /* ---------------  PIPE COMMAND ------------------- */
        else if (strcmp(args[arg_count], "|") == 0) {
            args[arg_count] = NULL;
            jobType = 3;
            break;
        }
        
        /* --------------  DONT WAIT COMMAND --------------- */
        else if (strcmp(args[arg_count], "&") == 0) {
            args[arg_count] = NULL;
            jobType = 4;
            break;
        }
        arg_count++;
    }
    
    switch(jobType) {
        case 0 :
            executeNormally(args);
            break;
            
        case 1 :
            executeWithInput(args, arg_count);
            break;
        
        case 2  :
            executeWithOutput(args, arg_count);
            break;
        
        case 3  :
            executeWithPipe(args, arg_count);
            break;
      
        case 4  :
            executeWithoutWait(args);
            break;
    }
}

int main(void) {
    char *args[MAX_LINE/2 + 1]; // command line arguments
    int should_run = 1;         // flag to determine when to exit program
    
    char *history_args[MAX_LINE/2 + 1];         // history cmd line args
    history_args[0] = NULL;
    
    while (should_run) {
        printf("osh>");
        fflush(stdout);
        
        long bytes_read;
        size_t size = MAX_LINE;
        char *string;
        string = (char *) malloc (size);
        
        // get line from terminal
        bytes_read = getline(&string, &size, stdin);

        // terminal command was not read
        if (bytes_read == -1) {
            printf("Error: Did not read command!\n");
            exit(EXIT_FAILURE);
        }
        
        const char s[2] = " \n";        // delimiter for strtok
        char *token;

        // get the first token
        token = strtok(string, s);
        int i = 0;

        // nothing is entered to command line
        if (token == NULL) {
            break;
        }
        
        // tokenize the string into the args char array
        while( token != NULL ) {
            args[i] = token;
            token = strtok(NULL, s);
            i++;
        }
        args[i] = NULL;
        
        // if exit is typed, end while loop
        if (strcmp(args[0], "exit") == 0) {
            if (args[1] != NULL) {
                printf("Error: Invalid Command\n");
            } else {
                should_run = 0;
                break;
            }
        }
    
        /* --------------  HISTORY COMMAND --------------- */
        if (strcmp(args[0], "!!") == 0) {
            // error if anything but !!
            if (args[1] != NULL) {
                printf("Error: Invalid Command\n");
            }
            // check if there is a previous command
            else if (history_args[0] == NULL) {
                printf("Error: No commands in history.\n");
            }
            
            else {
                // echo previous command to the console
                for (int i = 0; history_args[i] != NULL; i++) {
                    printf("%s ", history_args[i]);
                }
                printf("\n");
                
                // execute previous command
                runCommand(history_args);
            }
        } else {    /* --------------  OTHER COMMANDS --------------- */
            // save copy of command in history
            for (int i = 0; args[i] != NULL; i++) {
                history_args[i] = (char *) malloc(41);
                strcpy(history_args[i], args[i]);
            }
            history_args[i] = NULL;
            
            // execute command
            runCommand(args);
        }
        free(string);
    }
    return 0;
}
