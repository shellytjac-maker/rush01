#include <stdio.h>
#include <stdlib.h>

int	parse_clue(int *clue, int argc, char *argv[]);
int	validate(int **grid, int pos, int *clue);
void	print_grid(int **grid);

int	main(int argc, char *argv[])
{
	int	*clue;
	int	**grid;
	int	i;
	int	status;

	clue = malloc(sizeof(int) * 16);
	if (!clue)
	{
		printf("Error\n");
		return (1);
	}
	grid = malloc(sizeof(int *) * 4);
	if (!grid)
	{
		free(clue);
		printf("Error\n");
		return (1);
	}
	i = 0;
	while (i < 4)
	{
		grid[i] = malloc(sizeof(int) * 4);
		if (!grid[i])
		{
			while (i > 0)
			{
				i--;
				free(grid[i]);
			}
			free(grid);
			free(clue);
			printf("Error\n");
			return (1);
		}
		grid[i][0] = 0;
		grid[i][1] = 0;
		grid[i][2] = 0;
		grid[i][3] = 0;
		i++;
	}
	status = 0;
	if (!parse_clue(clue, argc, argv))
	{
		printf("Error\n");
		status = 1;
	}
	else if (validate(grid, 0, clue))
	{
		print_grid(grid);
	}
	else
	{
		printf("Error\n");
		status = 1;
	}
	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	free(clue);
	return (status);
}