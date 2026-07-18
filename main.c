#include <stdio.h>
#include <unistd.h>

int	parse_input(char *str, int *clues);

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4] = {0};

	if (argc == 2)
	{
		parse_input(argv[1], clues);
		printf(" %ls", clues);
	}
	return (0);
}
