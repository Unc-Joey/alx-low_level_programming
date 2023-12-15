#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
        printf("#cisfun$ ");

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("\n");
            break; // Handle end-of-file condition (Ctrl+D)
        }

        // Remove the trailing newline character
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
        {
            printf("Exiting shell\n");
            break;
        }

        // Fork a new process
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            // Child process
            if (execlp(command, command, (char *)NULL) == -1)
            {
                fprintf(stderr, "./shell: %s: No such file or directory\n", command);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // Parent process
            wait(NULL); // Wait for the child process to finish
        }
    }

    return (0);
}

