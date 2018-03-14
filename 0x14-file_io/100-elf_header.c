#include "holberton.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(STDERR_FILENO, "usage: elf_header elf_filename\n", 31);
	}
}
