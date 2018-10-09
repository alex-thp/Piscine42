/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gangbang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 17:21:04 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/25 17:21:09 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_sinit(t_coord *pt)
{
	int i;

	i = 0;
	pt->x = 0;
	pt->y = 0;
	pt->max = 0;
	pt->nblines = 0;
	pt->nbcol = 0;
	pt->deadline = 1;
	pt->empty = '0';
	pt->full = '0';
	pt->write = '0';
	while (pt->intab[i])
		free(pt->intab[i++]);
	while (pt->tab[i])
		free(pt->tab[i++]);
}

void	ft_tournante(char *av, t_coord *pt)
{
	int i;
	// int j;

	i = 0;
	ft_pre_char_read(av, pt);
	ft_parse_first_char(ft_first_char_read(av));
	if (ft_file_len(av, pt) == 1)
		printf("Bon fichier\n");
	else
		printf("gros fdp\n");
	printf("col init = %d\n", pt->nbcol);
	// while (i < pt->nblines)
	// {
	// 	ft_double_line(pt, av);
	// 	j = 0;
	// 	while (j < 2)
	// 	{
	// 		ft_charconv(pt, pt->empty, pt->full, j);
	// 		ft_bsq_change_line(pt, i);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// printf("%d\n", pt->nblines);
	// printf("%d\n", pt->nbcol);
	// ft_writetab(av, pt);
}
