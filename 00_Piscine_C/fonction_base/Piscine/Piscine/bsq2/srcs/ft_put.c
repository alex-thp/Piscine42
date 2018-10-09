/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:58:37 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/25 13:58:39 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar_out(char c, int output)
{
	write(output, &c, 1);
}

void	ft_putstr_out(char *str, int output)
{
	while (*str)
		write(output, str++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar_out('8', 1);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar_out('-', 1);
			nb = -nb;
		}
		if (nb < 10)
		{
			ft_putchar_out((nb % 10) + '0', 1);
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putchar_out((nb % 10) + '0', 1);
		}
	}
}
