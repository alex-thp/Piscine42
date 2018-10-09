int		ft_unsigned_atoi(char *str)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (str[i + 3] != '\n')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + str[i] - '0';
			i++;
		}
		else
			return (0);
	}
	return (nb);
}
