
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 14:00:06 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/25 14:00:08 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int ac, char **av)
{
	int i;
	t_coord *pt;

	i = 1;
	if(!(pt = (t_coord*)malloc(sizeof(t_coord))))
		return (0);
	if (ac == 1)
	{
		write(2, "Usage : This program take files as argument.\n", 45);
		return (0);
	}
	while (i < ac)
	{
		if (i > 1)
			ft_sinit(pt);
		ft_tournante(av[i], pt);
		printf("%d\n", i);
		i++;
	}
	return (0);
}
