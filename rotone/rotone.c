#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	str = argv[1];
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			if (*str == 'z')
				ft_putchar('a');
			else
				ft_putchar(*str + 1);
		}
		else if (*str >= 'A' && *str <= 'Z')
		{
			if (*str == 'Z')
				ft_putchar('A');
			else
				ft_putchar(*str + 1);
		}
		else
			ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
	return (0);
}
