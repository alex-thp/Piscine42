/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 23:53:24 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/23 23:53:26 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *add;

	add = ft_create_elem(data);
	add->next = *begin_list;
	*begin_list = add;
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

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*list;

	i = 0;
	list = begin_list;
	if (list == NULL)
		return (0);
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*last;

	last = begin_list;
	while (last)
	{
		if (last->next == NULL)
			return (last);
		last = last->next;
	}
	return (NULL);
}

int main(int argc, char **argv) {


	t_list *list = ft_list_push_params(argc, argv);
	printf("%d\n", ft_list_size(list));
	printf("%s\n", ft_list_last(list)->data);

	return 0;
}
