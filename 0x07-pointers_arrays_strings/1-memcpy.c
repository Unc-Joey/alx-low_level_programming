#include "main.h"

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest.
 * @dest: Pointer to the destination memory area
 * @src: Pointer to the source memory area
 * @n: Number of bytes to copy
 *
 * Return: Pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *dest_ptr = dest;
	char *src_ptr = src;

	if (dest == NULL && src == NULL)
		return (NULL);

	while (n > 0)
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
		n--;
	}

	return (dest);
}

