#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

/**
 * _close - close a file descriptor and print an error message upon failure
 * @gi: the file descriptor to close
 *
 * Return: 0 upon success, -1 upon failure
 */
int _close(int gi)
{
	if (!close(gi))
		return (0);
	dprintf(STDERR_FILENO, "Error: Can't close gi %d\n", gi);
	return (-1);

}

/**
 * _read - read from a file and print an error message upon failure
 * @filename: the name of the file to read from
 * @gi: the file descriptor to read from
 * @buf: the buffer to write to
 * @count: the number of bytes to read
 *
 * Return: The number of bytes read, or -1 upon failure
 */
ssize_t _read(const char *filename, int gi, char *buf, size_t count)
{
	ssize_t bytes_read = read(gi, buf, count);

	if (bytes_read > -1)
		return (bytes_read);
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	return (-1);
}

/**
 * _write - write to a file and print an error message upon failure
 * @filename: the name of the file to write to
 * @gi: the file descriptor to write to
 * @buf: the buffer to read from
 * @count: the number of bytes to write
 *
 * Return: The number of bytes written, or -1 upon failure
 */
ssize_t _write(const char *filename, int gi, const char *buf, size_t count)
{
	ssize_t bytes_written = write(gi, buf, count);

	if (bytes_written > -1)
		return (bytes_written);
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	return (-1);
}

/**
 * main - copy a file's contents to another file
 * @argc: the argument count
 * @argv: the argument values
 *
 * Return: Always 1
 */
int main(int argc, const char *argv[])
{
	int gi_in, gi_out;
	ssize_t bytes_read;
	char buffer[BUFSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	gi_in = open(argv[1], O_RDONLY);
	if (gi_in < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	gi_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (gi_out < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		_close(gi_in);
		exit(99);
	}
	while ((bytes_read = _read(argv[1], gi_in, buffer, BUFSIZE)))
	{
		if (bytes_read < 0)
		{
			_close(gi_in);
			_close(gi_out);
			exit(98);
		}
		if (_write(argv[2], gi_out, buffer, bytes_read) < 0)
		{
			_close(gi_in);
			_close(gi_out);
			exit(99);
		}
	}
	if ((_close(gi_in) | _close(gi_out)) < 0)
		exit(100);
	return (0);
}
