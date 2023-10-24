#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: The square matrix.
 * @size: The size of the matrix.
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0;
	int sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * size + i]; /* Sum of the main diagonal */
		sum2 += a[i * size + (size - 1 - i)]; /* Sum of the other diagonal */
	}

	printf("%d, %d\n", sum1, sum2);
}

