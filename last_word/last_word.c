#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *start, char *end)
{
	while (start < end)
	{
		ft_putchar(*start);
		start++;
	}
}

int	is_whitespace(char c)
{
	return (c == 9 || c == 32);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*end;
	char	*start;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	start = 0;
	end = 0;
	str = argv[1];
	while (*str)
	{
		if (!is_whitespace(*str))
		{
			start = str;
			while (*str && !is_whitespace(*str))
				str++;
			end = str;
		}
		else
			str++;
	}
	ft_putstr(start, end);
	ft_putchar('\n');
	return (0);
}
