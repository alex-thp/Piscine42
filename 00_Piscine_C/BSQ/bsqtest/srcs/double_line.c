/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:07:16 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/25 15:07:18 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_double_line(t_coord *pt, char *filename)
{
	char	*buf;
	int		file;
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * 2 * pt->nbcol + 1)))
		return;
	if (!(buf = (char*)malloc(sizeof(char) * 1)))
		return;
	file = open(filename, O_RDONLY);
	if (file < 0)
		return;
	ft_double_line_fill(file, buf, tab, pt);
}

void	ft_double_line_fill(int file, char *buf, char **tab, t_coord *pt)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j < 2)
	{
		printf("line : %d\n", j);
		while (buf[0] != '\n')
		{
			read(file, buf, 1);
		}
		j++;
	}
	read(file, buf, 1);
	printf("buf : %c\n", buf[0]);
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			read(file, buf, 1);
			tab[j][i++] = buf[0];
			printf("pointeur sur y = %d\n", j);
			printf("pointeur sur x = %d\n", i);
		}
		j++;
	}
	pt->tab = tab;
}
