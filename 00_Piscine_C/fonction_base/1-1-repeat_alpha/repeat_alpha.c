/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 13:26:28 by zzeller           #+#    #+#             */
/*   Updated: 2016/07/26 22:02:38 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		test(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	char	*str = "abcdefghijklmnopqrstuvwxyz";
	char	*str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			j = 0;
			write(1, &argv[1][i], 1);
			if (test(argv[1][i]))
			{
				while (str[j] && str2[j])
				{
					k = j;
					if (argv[1][i] == str[j] || argv[1][i] == str2[j])
					{
						while (k > 0)
						{
							write(1, &argv[1][i], 1);
							k--;
						}
					}
					j++;
				}
			}
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
