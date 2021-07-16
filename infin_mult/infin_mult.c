#include <unistd.h>
#include <stdlib.h>
#include "ftstr.h"

void	do_mult(char *res, int idx_n1, int idx_n2, char n1, char n2)
{
	int	unit_idx;
	int	change_idx;

	unit_idx = idx_n1 + idx_n2 + 1;
	change_idx = unit_idx - 1;
	res[unit_idx] += (n1 - '0') * (n2 - '0');
	res[change_idx] += res[unit_idx] / 10;
	res[unit_idx] %= 10;
}

char	*gen_mult(char *n1, char *n2)
{
	int	idx_n1;
	int	idx_n2;
	int	init_idx_n2;
	int	res_size;
	char	*res;

	res_size = ft_strlen(n1) + ft_strlen(n2);
	res = (char *)malloc(res_size + 1);
	ft_initzero(res, res_size + 1);
	res[res_size] = '\n';
	idx_n1 = ft_strlen(n1) - 1;
	init_idx_n2 = ft_strlen(n2) - 1;
	while (idx_n1 >= 0)
	{
		idx_n2 = init_idx_n2;
		while (idx_n2 >= 0)
		{
			do_mult(res, idx_n1, idx_n2, n1[idx_n1], n2[idx_n2]);
			idx_n2--;
		}	
		idx_n1--;
	}
	return (res);
}	

void	infin_mult (char *nb1, char *nb2)
{
	int	is_negative;

	is_negative = 0;
	if (!*nb1 || *nb1 == '0' || !*nb2 || *nb2 == '0')
	{
		ft_putchar('0');
		return ;
	}
	if (*nb1 == '-')
	{
		is_negative = !is_negative;
		nb1++;
	}
	if (*nb2 == '-')
	{
		is_negative = !is_negative;
		nb2++;
	}
	if (is_negative)
		ft_putchar('-');
	ft_print(gen_mult(nb1, nb2));
	ft_putchar('\n');	
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	infin_mult(argv[1], argv[2]);
	return (0);
}
