#include <unistd.h>

int	ft_strlen(char *str)
{
	int	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

int	ft_strnstr(char *haystack, char *needle, int n)
{
	int	success;
	int	i;
	int	j;

	success = 0;
	i = 0;
	while (haystack[i] && !success)
	{
		j = 0;
		success = 1;
		while (j <= n)
		{
			if (haystack[i] != needle[j])
			{
				success = 0;
				break ;
			}
			j++;
			i++;
		}
		i++;
	}
	return (success);
}

int	main(int argc, char *argv[])
{
	int	maxlen;
	int	res_start;
	int	res_end;
	int	curr_start;
	int	curr_end;
	int	success;
	char	*first_str;
	int	next_word;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	first_str = argv[1];
	maxlen = ft_strlen(first_str);
	res_start = 1;
	res_end = 0;
	success = 1;
	curr_start = 0;
	while (curr_start < maxlen)
	{
		success = 1;
		curr_end = curr_start;	
		while (curr_end < maxlen && success)
		{
			success = 1;
			next_word = 2;
			while (next_word < argc && success)
			{
				if (!ft_strnstr(argv[next_word], &first_str[curr_start], curr_end - curr_start))
				{
					success = 0;
					break;
				}
				next_word++;
			}
			if (!success)
				break;
			else if (curr_end - curr_start > res_end - res_start)
			{
				res_end = curr_end;
				res_start = curr_start;
			}
			curr_end++;
		}
		curr_start++;
	}
	if (res_end - res_start >= 0)
		write(1, &(first_str[res_start]), res_end - res_start + 1);
	write(1, "\n", 1);
	return (0);
}
