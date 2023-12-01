#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print.
 *         If the file can not be opened or read, return 0.
 *         If filename is NULL return 0.
 *         If write fails or does not write the expected amount of bytes, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd, bytesRead, bytesWritten;
    char *buffer;

    if (filename == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
    {
        close(fd);
        return (0);
    }

    bytesRead = read(fd, buffer, letters);
    if (bytesRead == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
    if (bytesWritten == -1 || (size_t)bytesWritten != (size_t)bytesRead)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    free(buffer);
    close(fd);

    return (bytesRead);
}

