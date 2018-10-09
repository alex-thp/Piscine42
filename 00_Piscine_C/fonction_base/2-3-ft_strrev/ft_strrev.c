/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller </var/mail/zzeller>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:28:16 by zzeller           #+#    #+#             */
/*   Updated: 2016/01/28 18:55:11 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
		i = i - 1;
		while (j < i)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			i--;
			j++;
		}
		return (str);
	}
	return (0);
}
