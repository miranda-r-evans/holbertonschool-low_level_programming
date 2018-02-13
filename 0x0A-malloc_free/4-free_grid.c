#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - frees the space made for a two dimensional array
 * @grid: the array that needs to be freed
 * @height: the height of the grid/length of the outer array
 */
void free_grid(int **grid, int height)
{
	int (i);

	if (grid == NULL)
		exit(0);

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
