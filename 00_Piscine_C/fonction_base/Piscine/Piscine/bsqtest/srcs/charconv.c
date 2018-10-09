/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charconv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 17:55:50 by ccharrie          #+#    #+#             */
/*   Updated: 2017/07/24 22:35:32 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_charconv(t_coord *pt, char a, char b, int n)
{
	int cpt;
	int *tab;

	cpt = 0;
	if (!(tab = (int *)malloc(sizeof(int) * pt->nbcol)))
		return;
	while (pt->tab[n])
	{
		if (pt->tab[n][cpt] == a || pt->tab[n][cpt] == b)
		{
			if (pt->tab[n][cpt] == a)
				tab[cpt] = pt->tab[n][cpt] - a + 11;
			else
				tab[cpt] = pt->tab[n][cpt] - b + 10;
			cpt++;
		}
		else
			exit(0);
	}
	tab[cpt] = 0;
	pt->intab[n] = tab;
	free(tab);
}
