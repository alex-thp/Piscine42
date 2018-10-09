/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 09:19:05 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/23 21:46:57 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	if (f(tab[i], tab[i + 1]) > 0)
	{
		while (f(tab[i], tab[i + 1]) != -1 && i < length - 1)
			i++;
	}
	else if (f(tab[i], tab[i + 1]) < 0)
	{
		while (f(tab[i], tab[i + 1]) != 1 && i < length - 1)
			i++;
	}
	else if (f(tab[i], tab[i + 1]) == 0)
	{
		while (f(tab[i], tab[i + 1]) == 0 && i < length - 1)
			i++;
	}
	if (i == length - 1)
		return (1);
	else
		return (0);
}
