/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_visibility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaung <htaung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:12:28 by tchaiyas          #+#    #+#             */
/*   Updated: 2026/07/20 11:52:14 by htaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(int line[4])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	row_check(int **grid, int row, int left_target, int right_target)
{
	int	line[4];
	int	reversed_line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][i];
		i++;
	}
	if (count_visible(line) != left_target)
	{
		return (0);
	}
	i = 0;
	while (i < 4)
	{
		reversed_line[i] = line[4 - 1 - i];
		i++;
	}
	if (count_visible(reversed_line) != right_target)
	{
		return (0);
	}
	return (1);
}

int	col_check(int **grid, int col, int top_traget, int bot_traget)
{
	int	line[4];
	int	reversed_col[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i][col];
		i++;
	}
	if (count_visible(line) != top_traget)
	{
		return (0);
	}
	i = 0;
	while (i < 4)
	{
		reversed_col[i] = line[4 - 1 - i];
		i++;
	}
	if (count_visible(reversed_col) != bot_traget)
	{
		return (0);
	}
	return (1);
}
