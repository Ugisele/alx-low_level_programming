#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * ilename: filename.
 * letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int out;
	ssize_t k, j;
	char *buf;

	if (!filename)
		return (0);

	out = open(filename, O_RDONLY);

	if (out == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	k = read(out, buf, letters);
	j = write(STDOUT_FILENO, buf, k);

	close(out);

	free(buf);

	return (j);
}
