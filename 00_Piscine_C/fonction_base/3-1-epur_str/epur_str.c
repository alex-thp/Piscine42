/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller </var/mail/zzeller>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:45:44 by zzeller           #+#    #+#             */
/*   Updated: 2016/01/21 20:02:41 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int	i;
	int	j;
	int	ok;
	int	space;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '	')
			i++;
		while (av[1][i] != '\0')
		{
			if (av[1][i] != ' ' && av[1][i] != '	')
			{
				ft_putchar(av[1][i]);
				i++;
			}
			else while (av[1][i] == ' ' || av[1][i] == '	')
			{
				j = i;
				ok = 0;
				space = 0;
				while (av[1][j] != '\0')
				{
					if (av[1][j] == ' ' || av[1][j] == '	')
						j++;
					else if (av[1][j] != ' ' && av[1][j] != '	')
					{
						ok = 1;
						j++;
					}
				}
				if (ok == 1)
				{
					j = i;
					while (av[1][j] == ' ' || av[1][j] == '	')
					{
						if (av[1][j] == ' ')
						{
							space = 1;
							j++;
						}
						else if (av[1][j] == '	')
							j++;
					}
					if ((av[1][i] == ' ' || av[1][i] == '	') && av[1][i + 1] != ' ' && av[1][i + 1] != '	')
					{
						ft_putchar(' ');
						i++;
					}
					else
						i++;
				}
				else
					i++;
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
