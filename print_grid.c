#include <stdio.h>

void	print_grid(int grid[4][4])
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			printf("%d", grid[r][c]);
			if (c < 3)
				printf(" ");
			c++;
		}
		printf("\n");
		r++;
	}
}