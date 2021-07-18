#include <unistd.h>

//helper func to print a character to stdout
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//helper func that returns the length of a string
int	ft_strlen(char *str)
{
	int	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

//helper func to initialize a string with null characters
void	ft_initzero(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
		str[i++] = 0;
}

//helper function to print out a string until the end of string character (\n used a newline in this case)
void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 0)
		i++;
	while (str[i] != '\n')
		ft_putchar(str[i++] + '0');
}
