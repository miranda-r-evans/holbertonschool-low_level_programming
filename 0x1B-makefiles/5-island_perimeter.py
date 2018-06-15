#!/usr/bin/env python3
'''
function computes perimeter of island
input is grid of 1's and 0's
1 is land, 0 is sea
no lakes
no diagonals
'''


def island_perimeter(grid):
        ''' computes perimeter of island '''

        area = 0

        for row in grid:
                for column in row:
                        if column == 1:
                                area += 1

        return area * 2 + 2
