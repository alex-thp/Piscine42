/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:24:42 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/10 18:34:41 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int a;
	int total;

	if (nb > 12 || nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	a = 1;
	total = 1;
	while (a <= nb)
	{
		total = total * a;
		a++;
	}
	return (total);
}
