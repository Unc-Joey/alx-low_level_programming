#include "main.h"

/**
 * _atoi - Convert a string to an integer.
 * @s: The input string.
 *
 * Return: The converted integer or 0 if no valid integer is found.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;
	int found = 0;

	while (s[i])
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
			found = 1;
		}
		else if (found)
			break;
		i++;
	}

	return (result * sign);
}

