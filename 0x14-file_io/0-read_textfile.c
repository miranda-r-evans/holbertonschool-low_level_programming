#include "holberton.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of file
 * @letters: number of characters to be printed to stdout
 *
 * Return: characters that were printed, or 0 if failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = open(filename, O_RDONLY);
	int r;
	char buf[1000] = { '\0' };

	if (fd == -1)
		return (0);

	r = read(fd, buf, letters);

	close(fd);

	if (r < 1)
		return (0);

	buf[999] = '\0';

	write(1, buf, 1000);

	if (r > 999)
		return (999);

	return (r);
}
