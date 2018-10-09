/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:29:46 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/16 19:49:32 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		test_str(char *src, char *to_find, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (to_find[i] != src[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (to_find[len] != '\0')
		len++;
	while (str[i] != '\0')
	{
		if (test_str(str + i, to_find, len) == 1)
			return (str + i);
		i++;
	}
	return (0);
}
