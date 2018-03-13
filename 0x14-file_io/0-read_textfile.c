#include "holberton.h"

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
