int	check_sudoku(int grid[4][4], int pos) // solve
{
	int i;
	int j;

	int row, col, num;
	row = pos / 4;
	col = pos % 4;
	i = 0;
	num = 1;
	while (num <= 4)
	{
		//--
		j = 0;
		while (i < 4)
		{
			if (!(grid[row][j] == num) || !(grid[j][col] == num))
			{
				grid[row][col] = num;
				pintf("integer %i", grid[row][col]);
				j++;
				if (check_sudoku(grid, pos + 1))
					return (1);
				grid[row][col] = 0;
			}
		}

		// int i;

		// i = 0;
		// while (i < 4)
		//{
		//	if (grid[row][i] == num || grid[i][col] == num)
		//		return (0);
		//	i++;
		//}
		// return (1);
		///--
		// if (is_safe(grid, row, col, num))
		//{
		// grid[row][col] = num;
		// if (check_sudoku(grid, pos + 1))
		//	return (1);
		// grid[row][col] = 0;
		//}
		num++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int	grid[4][4] = {0};

	check_sudoku(grid[4][4], 0);
}
