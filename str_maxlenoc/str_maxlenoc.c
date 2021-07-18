#include <unistd.h>

//helper func to help determine the length of the string
int	ft_strlen(char *str)
{
	int	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

//helper function to find a substring of n characters in the haystack
//1. while haystack is not end and while we havent found our match, do sth
//	-if the current hasystack character is not equal to needle character
//	- set success flag to 0 and break
//	- do this until n characters in compared
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

//VARIABLES
//maxlen = the maximum length of the common sunstring
//res_start = the starting pointer of the result (longest common substring)
//res_end = the end pointer of the result (longest common substring)
//curr_start = the current starting pointer 
//curr_end = the current ending pointer
//success = a flag that indicates if the substring is found at all words
//first_str = the string that we will be refrencing
//next_word = the word that we will be searching the substr in
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
