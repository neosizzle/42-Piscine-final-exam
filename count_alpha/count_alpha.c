#include <unistd.h>
#include <stdio.h>

int	is_lowalpha(char c)
{
	return (c >= 'a' && c <= 'z');
}

void	count_alpha(char *str, int i, int is_first, int count)
{
	int	j;
	char	curr;

	while (str[i])
	{
		if (is_lowalpha(str[i]))
		{
			if (is_first-- <= 0)
				printf(", ");
			curr = str[i];
			j = i;
			while (str[j])
			{
				if (str[j] == curr)
				{
					count++;
					str[j] = '0';
				}
				j++;
			}
			printf("%d%c", count,curr);
			count = 0;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*str;
	int	i;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	str = argv[1];
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	count_alpha(str, 0, 1, 0);
	printf("\n");
}
