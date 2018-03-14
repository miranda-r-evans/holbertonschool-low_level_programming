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

void _err(int i, char *fn)
{
	int len;

	switch (i) {
		case 97:
			len = _strlen("Usage: cp file_from file_to\n");
			write(STDERR_FILENO, "Usage: cp file_from file_to\n", len);
			exit(97);
			break;
		case 98:
			len = _strlen("Error: Can't read from file ");
			write(STDERR_FILENO, "Error: Can't read from file ", len);
			write(STDERR_FILENO, fn, _strlen(fn));
			write(STDERR_FILENO, "\n", 1);
			exit(98);
			break;
		case 99:
			len = _strlen("Error: Can't write to ");
			write(STDERR_FILENO, "Error: Can't write to ", len);
			write(STDERR_FILENO, fn, _strlen(fn));
			write(STDERR_FILENO, "\n", 1);
			exit(99);
			break;
		case 100:
			len = _strlen("Error: Can't close fd ");
			write(STDERR_FILENO, "Error: Can't close fd ", len);
			write(STDERR_FILENO, fn, _strlen(fn));
			write(STDERR_FILENO, "\n", 1);
			exit(100);
			break;
		default:
			break;
	}
}

/**
 * main - copied the content of a file to another file
 * @ac: number of elements input from command line
 * @av: elements from command line
 *
 * Return: 0 (Always Success)
 */
int main(int ac, char **av)
{
	int fdFrom;
	int fdTo;
	int r;
	char buf[1024] = { '\0' };

	if (ac != 3)
		_err(97, NULL);
	if (av[1] == NULL)
		_err(98, av[1]);
	if (av[2] == NULL)
		_err(99, av[2]);
	fdFrom = open(av[1], O_RDONLY);

	if (fdFrom < 0)
		_err(98, av[2]);

	fdTo = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fdTo == -1)
		_err(99, av[2]);

	do {
		r = read(fdFrom, buf, 1024);
		if (r < 0)
			_err(98, av[1]);
		if (write(fdTo, buf, r) != r)
			_err(99, av[2]);

	} while (r > 0);

	if (close(fdFrom) == -1)
	{
		_err(100, av[1]);
	}

	if (close(fdTo) == -1)
	{
		_err(100, av[2]);
	}

	return (0);
}
