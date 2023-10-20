#include "main.h"

/**
 * leet - Encodes a string into "1337".
 * @str: The input string to encode.
 *
 * Return: A pointer to the modified string.
 */
char *leet(char *str)
{
	int i, j;
	char leetLetters[] = "aAeEoOtTlL";
	char leetCodes[] = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; leetLetters[j] != '\0'; j++)
		{
			if (str[i] == leetLetters[j])
			{
				str[i] = leetCodes[j];
				break;
			}
		}
	}

	return str;
}

