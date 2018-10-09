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

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *add;

	add = ft_create_elem(data);
	add->next = *begin_list;
	*begin_list = add;
}

void 		ft_list_reverse(t_list **begin_list)
{
	t_list *list;
	t_list *tmp;

	list = *begin_list;
	tmp = *begin_list;
	while (list->next)
	{
		ft_list_push_front(&tmp, list->data);
		list = list->next;
		*begin_list = list;
	}
}

t_list		*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int 	i;

	i = 1;
	list = NULL;
	while (i < ac)
	{
		ft_list_push_front(&list, av[i]);
		i++;
	}
	return (list);
}

int 	main(int argc, char **argv)
{
	t_list 			*list;

	list = ft_list_push_params(argc, argv);
    ft_list_reverse(&list);
	printf("%s\n", list->data);

	return 0;
}
