#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The input string to be capitalized.
 *
 * Return: A pointer to the resulting string.
 */
char *cap_string(char *str)
{
	int i = 0;

	/* Capitalize the first character of the string */
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 'a' - 'A';

	while (str[i] != '\0')
	{
		/* Check for separators and capitalize the next character */
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		    str[i] == ',' || str[i] == ';' || str[i] == '.' ||
		    str[i] == '!' || str[i] == '?' || str[i] == '"' ||
		    str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}')
		{
			i++;
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 'a' - 'A';
		}
		else
		{
			i++;
		}
	}

	return (str);
}

