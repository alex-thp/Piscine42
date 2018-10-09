/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:35:37 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/23 17:35:40 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;

	list = *begin_list;
	if (list == NULL)
		*begin_list = ft_create_elem(data);
	while (list)
	{
		if (list->next == NULL)
		{
			list->next = ft_create_elem(data);
			return ;
		}
		list = list->next;
	}
}
