#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - allocates a space in memory for a two dimensional array
 * @width: width of grid/length of inner array
 * @height: height of grid/length of outer array
 *
 * Return: a pointer to the array, or NULL if failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i;
	int j;

	if (width < 1 || height < 1)
		return (NULL);

	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
			return (NULL);

		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
