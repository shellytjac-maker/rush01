#include <stdio.h>

int	check_sudoku(int num, int grid[4][4], int pos)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = pos / 4;
	col = pos % 4;
	
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
