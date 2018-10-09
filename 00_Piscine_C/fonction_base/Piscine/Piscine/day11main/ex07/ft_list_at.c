/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 10:57:25 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/27 10:57:27 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*list;
	unsigned int	i;

	i = 1;
	list = begin_list;
	while (list)
	{
		if (i == nbr)
		{
			return (list);
		}
		i++;
		list = list->next;
	}
	return (NULL);
}

void		ft_list_push_front(t_list **begin_list, void *data)
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

int main(int argc, char **argv)
{
	t_list 			*list;
	unsigned int 	nb;

	nb = 5;
	list = ft_list_push_params(argc, argv);
    printf("%s\n", ft_list_at(list, nb)->data);

	return 0;
}
