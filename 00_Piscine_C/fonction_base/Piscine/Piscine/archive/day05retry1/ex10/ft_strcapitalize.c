/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:19:30 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/12 18:56:28 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	str = ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		else if ((str[i] >= 'a' && str[i] <= 'z') && ((str[i - 1] < '0' ||
				str[i - 1] > '9') && (str[i - 1] < 'A' || str[i - 1] > 'Z') &&
				(str[i - 1] < 'a' || str[i - 1] > 'z')))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
