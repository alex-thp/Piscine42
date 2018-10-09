/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 12:17:59 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/18 12:18:03 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_nblet(char *str)
{
	int i;

	i = 0;
	while ((str[i] != '\n' && str[i] != '\t' && (str[i] != ' '
	&& str[i] != '\0')))
	{
		i++;
	}
	return (i);
}

char	*ft_cplet(char *dest, char *str)
{
	int	i;

	i = 0;
	while ((str[i] != '\n' && str[i] != '\t' && (str[i] != ' ')))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_nbmot(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (((str[i] < '\t' || str[i] > '\v') && str[i] != ' ') && (i == 0
		|| (str[i - 1] >= '\t' && str[i - 1] <= '\v') || str[i - 1] == ' '))
			len += 1;
		i++;
	}
	return (len);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * ft_nbmot(str) + 1);
	if (tab == NULL)
		return (0);
	while (str[i])
	{
		if (((str[i] < '\t' || str[i] > '\v') && str[i] != ' ') && (i == 0
		|| (str[i - 1] >= '\t' && str[i - 1] <= '\v') || str[i - 1] == ' '))
		{
			tab[j] = (char *)malloc(sizeof(char) * ft_nblet(str + i));
			if (tab[j] == NULL)
				return (0);
			tab[j] = ft_cplet(tab[j], str + i);
			j++;
			i = i + ft_nblet(str + i);
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
