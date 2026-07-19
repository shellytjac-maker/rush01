/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacobs <sjacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:31:09 by sjacobs           #+#    #+#             */
/*   Updated: 2026/07/19 15:53:41 by sjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_sudoku(int grid[4][4], int i)
{
	int	x;
	int	n;

	if (i == 16)
		return (1);
	n = 1;
	while (n <= 4)
	{
		x = 0;
		while (x < 4)
		{
			if (grid[x][i % 4] == n || grid[i / 4][x] == n)
				break ;
			x++;
		}
		if (x == 4)
		{
			grid[i / 4][i % 4] = n;
			if (check_sudoku(grid, i + 1))
				return (1);
			grid[i / 4][i % 4] = 0;
		}
		n++;
	}
	return (0);
}

void	print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	grid[4][4];

	init_grid(grid);
	if (check_sudoku(grid, 0))
		print_grid(grid);
	return (0);
}
