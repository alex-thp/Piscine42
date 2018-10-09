/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 10:57:41 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/27 10:57:43 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list;
	t_list	*tmp;

	list = *begin_list;
	while ((*cmp)(list->data, data_ref) == 0 && *begin_list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	while (list && list->next)
	{
		if ((*cmp)(list->next->data, data_ref) == 0)
		{
			tmp = list->next;
			list->next = tmp->next;
			free(tmp);
		}
		if (list->next)
			list = list->next;
	}
}
