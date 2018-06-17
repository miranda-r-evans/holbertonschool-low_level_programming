#!/usr/bin/python3
'''
function computes perimeter of island
input is grid of 1's and 0's
1 is land, 0 is sea
no lakes
no diagonals
'''


def island_perimeter(grid):
        ''' computes perimeter of island '''

        perimeter = 0

        for i in range(len(grid)):
                for j in range(len(grid[0])):
                        if grid[i][j] == 1:
                                if j - 1 < 0 or grid[i][j-1] == 0:
                                        perimeter += 1
                                if j + 1 >= len(grid[0]) or grid[i][j+1] == 0:
                                        perimeter += 1
                                if i - 1 < 0 or grid[i-1][j] == 0:
                                        perimeter += 1
                                if i + 1 >= len(grid) or grid[i+1][j] == 0:
                                        perimeter += 1
        return perimeter
