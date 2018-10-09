/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:16:18 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/10 00:05:46 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int neg;
	int i;
	int nb;

	nb = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= '\r' && str[i] <= '\t') || str[i] == ' ')
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (neg * nb);
}