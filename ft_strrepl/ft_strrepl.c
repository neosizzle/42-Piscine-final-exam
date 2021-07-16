char	g_res[2048];

char	*ft_strrepl(char *str, char c1, char c2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c1)
			g_res[i] = c2;
		else
			g_res[i] = str[i];
		i++;
	}
	g_res[i] = 0;
	str = g_res;
	return (str);
}
