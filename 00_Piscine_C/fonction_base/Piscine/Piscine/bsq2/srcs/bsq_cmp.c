/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:57:09 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/25 13:57:13 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_bsq_cmp(int *line1, int *line2, int index)
{
	int min;

	min = line2[index - 1];
	if (line1[index - 1] < min)
		min = line1[index - 1];
	if (line1[index] < min)
		min = line1[index];
	min ++;
	return (min);
}

void 	ft_bsq_get_max(int *line, int length, int line_number, t_coord *pt)
{
	int max;
	int i;

	i = 0;
	while (i < length)
	{
		if (line[i] > pt->max)
			max = line [i];
		i++;
	}
	pt->x = i;
	pt->y = line_number;
	pt->max = max;
}

void	ft_bsq_change_line(t_coord *pt, int line_number)
{
	int i;
	int *line1;
	int *line2;
	int	length;

	line1 = pt->intab[0];
	line2 = pt->intab[1];
	i = 1;
	length = pt->nbcol;
	while (i < length)
	{
		if (line2[i] != 0)
			line2[i] = ft_bsq_cmp(line1, line2, i);
		i++;
	}
	ft_bsq_get_max(line2, length, line_number, pt);
	pt->intab[1] = line2;
}
