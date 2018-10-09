/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 12:30:22 by zzeller           #+#    #+#             */
/*   Updated: 2015/08/27 11:52:54 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int i;
	char f;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '	')
			i++;
		while ((argv[1][i] != ' ' && argv[1][i] != '	')
			&& argv[1][i] != '\0')
		{
			f = argv[1][i];
			write(1, &f, 1);
			i++;
		}
		write(1, "\n", 1);
		return (0);
	}
	else
		write(1, "\n", 1);
	return (0);
}
