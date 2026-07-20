/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaung <htaung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:30:28 by htaung            #+#    #+#             */
/*   Updated: 2026/07/20 12:16:28 by htaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		parse_clue(int *clue, int argc, char *argv[]);
int		validate(int **grid, int pos, int *clue);
void	print_grid(int **grid);

void	free_all(int **grid, int *clue, int size)
{
	int	i;

	if (grid)
	{
		i = -1;
		while (++i < size)
			free(grid[i]);
		free(grid);
	}
	if (clue)
		free(clue);
}

int	**init_grid(void)
{
	int	**g;
	int	i;
	int	j;

	g = malloc(sizeof(int *) * 4);
	if (!g)
		return (0);
	i = -1;
	while (++i < 4)
	{
		g[i] = malloc(sizeof(int) * 4);
		if (!g[i])
		{
			free_all(g, 0, i);
			return (0);
		}
		j = -1;
		while (++j < 4)
			g[i][j] = 0;
	}
	return (g);
}

int	main(int argc, char *argv[])
{
	int	*clue;
	int	**grid;
	int	status;

	status = 1;
	clue = malloc(sizeof(int) * 16);
	grid = init_grid();
	if (clue && grid)
	{
		if (parse_clue(clue, argc, argv) && validate(grid, 0, clue))
		{
			print_grid(grid);
			status = 0;
		}
	}
	free_all(grid, clue, 4);
	return (status);
}
