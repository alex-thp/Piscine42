/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 13:42:03 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/17 09:57:40 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int j;

	j = 0;
	while (j < size && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < size)
	{
		dest[j] = '\0';
	}
	return (j);
}
