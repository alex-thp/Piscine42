/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavalar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 12:04:25 by tlavalar          #+#    #+#             */
/*   Updated: 2017/07/16 12:04:27 by tlavalar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_print_sud(int sud[9][9]);
int		ft_error_check(int argc, char **argv);
int		ft_l_ok(int k, int sud[9][9], int i);
int		ft_c_ok(int k, int sud[9][9], int j);
int		ft_s_ok(int k, int sud[9][9], int i, int j);
int		ft_is_ok(int sud[9][9], int place);
void	ft_tab_nul(int tab[9]);
int		ft_max(int tab[9]);
int		ft_check_l(int sud[9][9]);
int		ft_check_c(int sud[9][9]);
int		ft_check_s(int sud[9][9], int i, int j);
int		ft_move_s(int sud[9][9]);
int		ft_error_check3(int sud[9][9]);
int		ft_error_check2(int argc, char **argv);
int		ft_error_check(int argc, char **argv);

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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while ((str[i]) != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_print_sud(int sud[9][9])
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
	int		i;
	int		j;
	int		sud[9][9];

	i = 1;
	if (ft_error_check(argc, argv) == 0)
		return (0);
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
				sud[i - 1][j] = 0;
			else
				sud[i - 1][j] = (argv[i][j]) - '0';
			j++;
		}
		i++;
	}
	if (ft_error_check3(sud) == 0)
		return (0);
	ft_is_ok(sud, 0) == 1 ? ft_print_sud(sud) : ft_putstr("Error\n");
}
