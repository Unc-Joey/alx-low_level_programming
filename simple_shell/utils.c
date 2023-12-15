#include "shell.h"

/**
 * remove_newline - Remove the trailing newline character from a string
 * @str: The input string
 */
void remove_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

