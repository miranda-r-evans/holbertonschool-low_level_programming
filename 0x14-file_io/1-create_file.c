#include "holberton.h"

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

int create_file(const char *filename, char *text_content)
{
	int fd;
	int len;

	if (filename == NULL)
		return (-1);

	if (access(filename, F_OK) != -1)
		fd = open(filename, O_TRUNC | O_WRONLY);
	else
		fd = open(filename, O_CREAT | O_WRONLY, 0600);

	if (fd < 0)
		return (-1);

	if (text_content == NULL)
		return (1);

	len = _strlen(text_content) + 1;
	if (write(fd, text_content, len) < 0)
		return (-1);

	close(fd);

	return (1);
}
