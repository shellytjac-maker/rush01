int	count_visible(int line[4])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;

	while(i < 4)
	{
		if(line[i] > max)
		{
			max = line[i]
			count++;
		}
		i++;
	}
	return(count)
}

int main(*)