#include <stdio.h>

int	sudoku_check(int num, int grid[4][4], int pos);
int	row_check(int grid[4][4], int row, int left_target, int right_target);
int	col_check(int grid[4][4], int col, int top_traget, int bot_traget);

int	validate(int grid[4][4], int pos, int clue[16])
{
	int	row;
	int	col;
	int	num;
	int	valid;

	if (pos == 16)
		return (1);
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (sudoku_check(num, grid, pos))
		{
			grid[row][col] = num;
			valid = 1;
			if (col == 3 && !row_check(grid, row, clue[8 + row], clue[12 + row]))
				valid = 0;
			if (row == 3 && !col_check(grid, col, clue[col], clue[4 + col]))
				valid = 0;
			if (valid)
			{
				if (validate(grid, pos + 1, clue))
					return (1);
			}
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}