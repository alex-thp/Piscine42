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

int		ft_check_l(int sud[9][9])
{
	int tab[9];
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		ft_tab_nul(tab);
		while (j < 9)
		{
			if (sud[i][j] == '.')
				;
			else
				tab[sud[i][j] - 1]++;
			j++;
		}
		if (ft_max(tab) > 1)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_c(int sud[9][9])
{
	int tab[9];
	int i;
	int j;

	j = 0;
	while (j < 9)
	{
		i = 0;
		ft_tab_nul(tab);
		while (i < 9)
		{
			if (sud[i][j] == '.')
				;
			else
				tab[sud[i][j] - 1]++;
			i++;
		}
		if (ft_max(tab) > 1)
			return (0);
		j++;
	}
	return (1);
}

int		ft_check_s(int sud[9][9], int i, int j)
{
	int tab[9];
	int l;
	int m;

	ft_tab_nul(tab);
	l = i;
	while (l < i + 3)
	{
		m = j;
		while (m < j + 3)
		{
			if (sud[l][m] == '.')
				;
			else
				tab[sud[l][m] - 1]++;
			m++;
		}
		l++;
	}
	if (ft_max(tab) > 1)
		return (0);
	return (1);
}

int		ft_move_s(int sud[9][9])
{
	int i;
	int j;

	i = 0;
	while (i <= 6)
	{
		j = 0;
		while (j <= 6)
		{
			ft_check_s(sud, i, j);
			j = j + 3;
		}
		i = i + 3;
	}
	return (1);
}
