/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 15:35:20 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/16 17:13:10 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while ((str[i]) != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '1' || str[i] > '9') && str[i] != '.')
			return (1);
		i++;
	}
	if (i != 9)
		return (1);
	return(0);
}


void	affichage(int sud[9][9])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar((sud[i][j] + '0'));
			if (j < 8)
				ft_putchar((' '));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		sud[9][9];
	int		error;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			str = argv[i];
			error = ft_error(str);
			if (str[j] == '.')
				sud[i - 1][j] = 0;
			else
				sud[i - 1][j] = (str[j]) - '0';
			j++;
		}
		i++;
	}
	if (error == 0)
		affichage(sud);
	else
		write(1, "Error\n", 6);
}
