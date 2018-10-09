/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:07:48 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/25 15:07:50 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		*ft_strcat(char *dest, char *src)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	while (k <= j)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_first_char_read(char *str)
{
	int		file;
	char	*buf;
	int		i;
	char	*tab;

	i = 0;
	if (!(buf = malloc(sizeof(char) + 1)))
		return (0);
	if (!(tab = (char*)malloc(sizeof(char) + 1)))
		return (0);
	file = open(str, O_RDONLY);
	if (file < 0)
		ft_putstr_out("map error\n Can't open file\n", 2);
	while (*buf != '\n')
	{
		ft_strcat(tab, buf);
		tab = ft_realloc(tab, i, (i + 1));
		read(file, buf, 1);
		i++;
	}
	tab[i] = '\0';
	close(file);
	return (tab);
}

void		ft_parse_first_char(char *str, t_coord *pt)
{
	int		len;
	int		i;
	char	tmp[5];
	int		nblignes;

	nblignes = ft_unsigned_atoi(str);
	if (nblignes <= 0)
		ft_putstr_out("map error\nNot enough lines\n", 2);
	i = 0;
	len = ft_strlen(str);
	while (i <= 4)
		tmp[i++] = str[len--];
	tmp[i] = '\0';
	if (tmp[2] == tmp[3] || tmp[3] == tmp[4] || tmp[2] == tmp[4])
		ft_putstr_out("map error\nArgs are the same\n", 2);
	pt->full = tmp[2];
	pt->empty = tmp[3];
	pt->write = tmp[4];
	pt->nblines = nblignes;
	pt->nbcol = ft_strlen(str);
}
