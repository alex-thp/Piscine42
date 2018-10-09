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
int		ft_error_check3(int sud[9][9]);
int		ft_error_check2(int argc, char **argv);
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

int		ft_error_check3(int sud[9][9])
{
	if (ft_check_l(sud) == 0 || ft_check_c(sud) == 0 || ft_move_s(sud) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int		ft_error_check2(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (c != '.' && (c < '1' || c > '9'))
				return (0);
			j++;
		}
		if (j != 9)
			return (0);
		i++;
	}
	return (1);
}

int		ft_error_check(int argc, char **argv)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (argc != 10 || ft_error_check2(argc, argv) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}
