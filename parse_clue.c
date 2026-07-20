/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaung <htaung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:30:22 by htaung            #+#    #+#             */
/*   Updated: 2026/07/20 11:30:49 by htaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_clue(int *clue, int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc != 2)
		return (0);
	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			if (j >= 16)
				return (0);
			clue[j] = argv[1][i] - '0';
			j++;
		}
		else if (argv[1][i] != ' ')
		{
			return (0);
		}
		i++;
	}
	if (j != 16)
		return (0);
	return (1);
}
