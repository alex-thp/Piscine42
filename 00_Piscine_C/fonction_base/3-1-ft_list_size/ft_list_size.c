/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller </var/mail/zzeller>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 19:31:19 by zzeller           #+#    #+#             */
/*   Updated: 2016/01/07 19:40:05 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list != 0)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}
