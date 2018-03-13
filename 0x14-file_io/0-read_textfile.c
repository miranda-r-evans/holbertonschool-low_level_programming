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
	int fd;
	int r;
	char buf[1000] = { '\0' };

	if (filename == NULL || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	r = read(fd, buf, letters);

	close(fd);

	if (r < 0)
		return (0);

	if (write(1, buf, r) != r)
		return (0);

	return (r);
}
