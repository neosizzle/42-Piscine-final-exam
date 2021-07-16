#include <stdlib.h>

int	is_whitespace(char c)
{
	return (c == 9 || c == 32 || c == '\n');
}

int	get_word_cnt(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		if (!is_whitespace(*str))
		{
			res++;
			while (*str && !is_whitespace(*str))
			str++;
		}
		else
			str++;
	}
	return (res);
}

void	ft_strcpy(char *dest, char *start, char *end)
{
	while (start < end)
	{
		*dest = *start;
		dest++;
		start++;
	}
	*dest = 0;
}

char	**ft_split(char *str)
{
	char	**res;
	char	*start;
	char	*end;
	int	i;

	res = (char **)malloc(sizeof(char *) * get_word_cnt(str) + 1);
	if (!res)
		return (0);
	i = 0;
	start = 0;
	end = 0;
	while (*str)
	{
		if (!is_whitespace(*str))
		{
			start = str;
			while (*str && !is_whitespace(*str))
				str++;
			end = str;
			res[i] = malloc(1024);
			ft_strcpy(res[i++], start, end);
		}
		else
			str++;
	}
	res[i] = 0;
	return (res);
}

/*
#include <stdio.h>
int	main()
{
	char **res = ft_split("");
	//printf("%s \n", *(res + 1));
	if (!*res)
		printf(":(");
	while (*res)
	{
		printf("%s,", *(res ++));
	}
	printf("\n");
}
*/
