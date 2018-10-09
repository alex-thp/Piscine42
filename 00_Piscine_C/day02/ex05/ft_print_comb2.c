/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:23:01 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/06 23:14:53 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_comb(int i)
{
	char a;
	char b;

	a = (i / 10) + 48;
	b = (i % 10) + 48;
	ft_putchar(a);
	ft_putchar(b);
}

void	ft_print(int i1, int i2)
{
	ft_comb(i1);
	ft_putchar(' ');
	ft_comb(i2);
	if (i1 < 98 && i2 <= 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int i1;
	int i2;

	i1 = 0;
	while (i1 <= 98)
	{
		i2 = i1 + 1;
		while (i2 <= 99)
		{
			ft_print(i1, i2);
			i2++;
		}
		i1++;
	}
}
