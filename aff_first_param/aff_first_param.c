#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putstr("\n");
		return (0);
	}
	ft_putstr(argv[1]);
	ft_putstr("\n");
	return (0);
}
