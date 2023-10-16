#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char password[84];
	int i, sum, r;

	sum = 0;
	srand(time(0));

	for (i = 0; sum < (2772 - 122); i++)
	{
		r = rand() % 62;
		password[i] = (r < 10) ? ('0' + r) : ((r < 36) ? ('A' + r - 10) : ('a' + r - 36));
		sum += password[i];
	}

	password[i] = 2772 - sum - '\0';
	printf("%s", password);

	return (0);
}
