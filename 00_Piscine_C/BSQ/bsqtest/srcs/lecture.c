/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:28:33 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/25 15:28:37 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_condition(t_coord *pt, int fd)
{
	int		i;
	int		j;
	char	buffer[1];

	i = 1;
	while (i < pt->nblines)
	{
		j = 1;
		while (j < pt->nbcol)
		{
			read(fd, buffer, 1);
			if (i <= pt->y && i >= (pt->y - pt->max + 1) && j <= pt->x
					&& j >= (pt->x - pt->max + 1))
				ft_putchar_out(pt->full, 1);
			else
				ft_putstr_out(buffer, 1);
			j++;
		}
		ft_putchar_out('\n', 1);
		i++;
	}
}

void	ft_writetab(char *av, t_coord *pt)
{
	int		fd;
	char	buffer[1];

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(2, "ERREUR\n", 7);
		return;
	}
	while (buffer[0] != '\n')
		read(fd, buffer, 1);
	read(fd, buffer, 1);
	ft_condition(pt, fd);
}
