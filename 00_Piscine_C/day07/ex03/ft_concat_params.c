/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 18:05:36 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/17 18:05:41 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *total, int argc, char **argv)
{
	int i;
	int j;
	int k;

	i = 1;
	k = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			total[k] = argv[i][j];
			k++;
			j++;
		}
		if (i != argc - 1)
		{
			total[k] = '\n';
			k++;
		}
		i++;
	}
	total[k] = '\0';
	return (total);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		arg_size;
	int		nb;
	char	*total;

	i = 1;
	nb = argc - 2;
	arg_size = 0;
	while (argv[i])
	{
		arg_size += ft_strlen(argv[i]);
		i++;
	}
	i = 0;
	nb = nb + arg_size;
	if (!(total = malloc(sizeof(total) * (nb + 1))))
		return (0);
	total = ft_strcat(total, argc, argv);
	return (total);
}
