#include "bsq.h"

void	ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

// void	ft_putstr_out(char *str, int output)
// {
// 	while (*str)
// 		write(output, str++, 1);
// }

// void	ft_putnbr(int nb)
// {
// 	if (nb == -2147483648)
// 	{
// 		ft_putnbr(nb / 10);
// 		ft_putchar_out('8', 1);
// 	}
// 	else
// 	{
// 		if (nb < 0)
// 		{
// 			ft_putchar_out('-', 1);
// 			nb = -nb;
// 		}
// 		if (nb < 10)
// 		{
// 			ft_putchar_out((nb % 10) + '0', 1);
// 		}
// 		if (nb >= 10)
// 		{
// 			ft_putnbr(nb / 10);
// 			ft_putchar_out((nb % 10) + '0', 1);
// 		}
// 	}
// }

int		ft_strlen(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
