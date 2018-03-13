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
	int len;

	if (ac != 3)
	{
		len = _strlen("Usage: cp file_from file_to\n");
		write(2, "Usage: cp file_from file_to\n", len);
		exit(97);
	}

	fdFrom = open(av[1], O_RDONLY);

	if (fdFrom == -1)
	{
		len = _strlen("Error: Can't read from file ");
		write(2, "Error: Can't read from file ", len);
		write(2, av[1], _strlen(av[1]));
		write(2, "\n", 1);
		exit(98);
	}

	if (access(av[2], F_OK) != -1)
		fdTo = open(av[2], O_TRUNC | O_WRONLY);
	else
		fdTo = open(av[2], O_CREAT | O_WRONLY, 0664);

	if (fdTo == -1)
	{
		write(2, "Error: Can't write to ", _strlen("Error: Can't write to "));
		write(2, av[2], _strlen(av[2]));
		write(2, "\n", 1);
		exit(99);
	}

	do {
		r = read(fdFrom, buf, 1024);
		write(fdTo, buf, r);
	} while (r != 0);

	if (close(fdFrom) == -1)
	{
		write(2, "Error: Can't close fd", _strlen("Error: Can't close fd"));
		write(2, av[1], _strlen(av[1]));
		write(2, "\n", 1);
		exit(100);
	}

	if (close(fdTo) == -1)
	{
		write(2, "Error: Can't close fd", _strlen("Error: Can't close fd"));
		write(2, av[2], _strlen(av[2]));
		write(2, "\n", 1);
		exit(100);
	}

	return (0);
}
