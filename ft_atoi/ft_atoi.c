int	ft_atoi(const char *str)
{
	int	res;
	int	polarity;

	res = 0;
	polarity = 1;
	while (*str == 32 || *str == 9)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			polarity *= -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * polarity);
}
