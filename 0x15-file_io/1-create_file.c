#include "main.h"

/**
 * create_file - creates a file
 * filename: filename.
 * text_content: content writed in the file.
 *
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int file;
	int new_text;
	int perm__;

	if (!filename)
		return (-1);

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (new_text = 0; text_content[new_text]; new_text++)
		;

	perm__ = write(file, text_content, new_text);

	if (perm__ == -1)
		return (-1);

	close(file);

	return (1);
}
