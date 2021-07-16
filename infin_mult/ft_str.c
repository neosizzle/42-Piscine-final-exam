#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

void	ft_initzero(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
		str[i++] = 0;
}

void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 0)
		i++;
	while (str[i] != '\n')
		ft_putchar(str[i++] + '0');
}
