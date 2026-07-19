#include <stdio.h>

int	parse_clue(int clue[16], int argc, char *argv[]);
int	validate(int grid[4][4], int pos, int clue[16]);
void	print_grid(int grid[4][4]);

int	main(int argc, char *argv[])
{
	int	clue[16];
	int	grid[4][4] = {0};

	if (!parse_clue(clue, argc, argv))
	{
		return (1);
	}
	if (validate(grid, 0, clue))
	{
		print_grid(grid);
	}
	return (0);
}