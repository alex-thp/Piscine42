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

int		ft_strlen(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_first_char_read(char *str)
{
	int		file;
	char	*buf;
	int		i;
	char	*tab;

	i = 0;
	if(!(buf = malloc(sizeof(char) + 1)))
		return (0);
	if(!(tab = (char*)malloc(sizeof(char) + 1)))
		return (0);
	file = open(str, O_RDONLY);
	if	(file < 0)
		printf("EROOsdnadnakdnR");
	while (*buf != '\n')
	{
		read(file, buf, 1);
		ft_strcat(tab, buf);
		ft_realloc(tab, i, (i + 1));
		i++;
	}
	return (tab);
}

int		ft_parse_first_char(char *str)
{
	int		len;
	int		i;
	char	tmp[5];

	i = 0;
	len = ft_strlen(str);
	while (i <= 4)
		tmp[i++] = str[len--];
	tmp[i] = '\0';
	if (tmp[2] == tmp[3] || tmp[3] == tmp[4] || tmp[2] == tmp[4])
	{
		ft_putstr_out("map error\n", 2);
		return (0);
	}
	printf("%c\n", tmp[2]);
	printf("%c\n", tmp[3]);
	printf("%c\n", tmp[4]);
	printf("%d\n", ft_unsigned_atoi(str));
	return (0);
}
