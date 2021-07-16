#include <stdlib.h>

int	g_idx;

void	itoa_helper(int nbr, char *res)
{
	if (nbr == -2147483648)
	{
		itoa_helper(nbr / 10, res);
		res[g_idx++] = 8 + '0';
		return ;
	}
	if (nbr < 10 && nbr >= 0)
	{
		res[g_idx++] = nbr + '0';
		return;
	}
	else if (nbr > 9)
	{
		itoa_helper(nbr / 10, res);
		res[g_idx++] = (nbr % 10) + '0';
	}
	else
	{
		res[g_idx++] = '-';
		itoa_helper(nbr * -1, res);
	}
}

char	*ft_itoa(int nbr)
{
	char	*res;

	g_idx = 0;
	res = (char *)malloc(2048);
	itoa_helper(nbr, res);
	res[g_idx] = 0;
	return (res);
}
