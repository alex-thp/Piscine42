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

int		ft_l_ok(int k, int sud[9][9], int i)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (sud[i][j] == k)
			return (0);
		j++;
	}
	return (1);
}

int		ft_c_ok(int k, int sud[9][9], int j)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (sud[i][j] == k)
			return (0);
		i++;
	}
	return (1);
}

int		ft_s_ok(int k, int sud[9][9], int i, int j)
{
	int l;
	int m;

	l = 3 * (i / 3);
	while (l < (3 * (i / 3) + 3))
	{
		m = 3 * (j / 3);
		while (m < (3 * (j / 3) + 3))
		{
			if (sud[l][m] == k)
				return (0);
			m++;
		}
		l++;
	}
	return (1);
}

int		ft_is_ok(int sud[9][9], int place)
{
	int i;
	int j;
	int k;

	if (place == 9 * 9)
		return (1);
	i = place / 9;
	j = place % 9;
	k = 1;
	if (sud[i][j] != 0)
		return (ft_is_ok(sud, place + 1));
	while (k <= 9)
	{
		if (ft_l_ok(k, sud, i) == 1 && (ft_c_ok(k, sud, j) == 1
			&& ft_s_ok(k, sud, i, j) == 1))
		{
			sud[i][j] = k;
			if (ft_is_ok(sud, place + 1))
				return (1);
		}
		k++;
	}
	sud[i][j] = 0;
	return (0);
}
