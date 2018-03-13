#include "holberton.h"

/**
 * _strlen - find length of string
 * @str: string to be evaluated
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		i++;
		str++;
	}

	return (i);
}

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: file to be edited
 * @text_content: text to be added
 *
 * Return: 1 if success, -1 if failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int len;

	if (filename == NULL || access(filename, F_OK) == -1)
		return (-1);
	else if (text_content == NULL)
		return (1);

	fd = open(filename, O_RDWR | O_APPEND);

	if (fd < 0)
		return (-1);

	len = _strlen(text_content);
	if (write(fd, text_content, len) < len)
		return (-1);

	close(fd);

	return (1);
}
