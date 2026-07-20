/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaung <htaung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:30:37 by htaung            #+#    #+#             */
/*   Updated: 2026/07/20 11:30:45 by htaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_sudoku(int num, int **grid, int pos)
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
