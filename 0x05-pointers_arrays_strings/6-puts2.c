#include "main.h"

/**
 * puts2 - Prints every other character of a string followed by a new line.
 * @str: The input string to be printed.
 */
void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i += 2;
	}

	_putchar('\n');
}

