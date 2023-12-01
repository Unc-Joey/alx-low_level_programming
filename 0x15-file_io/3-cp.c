#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/**
 * error_exit - Prints an error message and exits with a specified code.
 * @code: The exit code.
 * @message: The error message.
 */
void error_exit(int code, const char *message)
{
    dprintf(2, "%s\n", message);
    exit(code);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, read_result, write_result;
    char buffer[BUFF_SIZE];

    if (argc != 3)
        error_exit(97, "Usage: cp file_from file_to");

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file");

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        error_exit(99, "Error: Can't write to file");

    do
    {
        read_result = read(fd_from, buffer, BUFF_SIZE);
        if (read_result == -1)
            error_exit(98, "Error: Can't read from file");

        write_result = write(fd_to, buffer, read_result);
        if (write_result == -1 || write_result != read_result)
            error_exit(99, "Error: Can't write to file");

    } while (read_result > 0);

    if (close(fd_from) == -1)
        error_exit(100, "Error: Can't close fd");

    if (close(fd_to) == -1)
        error_exit(100, "Error: Can't close fd");

    return (0);
}

