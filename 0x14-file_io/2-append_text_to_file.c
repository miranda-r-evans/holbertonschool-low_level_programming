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

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int len;

	if (access(filename, F_OK) == -1)
		return (-1);
	else if (text_content == NULL)
		return (1);

	fd = open(filename, O_APPEND | O_WRONLY);

	if (fd < 0)
		return (-1);

	len = _strlen(text_content) + 1;
	if (write(fd, text_content, len) < 0)
		return (-1);

	close(fd);

	return(1);	
}
