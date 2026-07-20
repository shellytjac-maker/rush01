/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaung <htaung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:35:19 by htaung            #+#    #+#             */
/*   Updated: 2026/07/20 12:07:19 by htaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_sudoku(int num, int **grid, int pos);
int	row_check(int **grid, int row, int left_target, int right_target);
int	col_check(int **grid, int col, int top_traget, int bot_traget);
int	validate(int **grid, int pos, int *clue);

int	check_views(int **grid, int pos, int *clue)
{
	int	r;
	int	c;

	r = pos / 4;
	c = pos % 4;
	if (c == 3 && !row_check(grid, r, clue[8 + r], clue[12 + r]))
		return (0);
	if (r == 3 && !col_check(grid, c, clue[c], clue[4 + c]))
		return (0);
	return (1);
}

int	validate(int **grid, int pos, int *clue)
{
	int	num;

	if (pos == 16)
		return (1);
	num = 0;
	while (++num <= 4)
	{
		if (check_sudoku(num, grid, pos))
		{
			grid[pos / 4][pos % 4] = num;
			if (check_views(grid, pos, clue) && validate(grid, pos + 1, clue))
				return (1);
			grid[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}
