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

void	ft_print(void *data)
{
	printf("%s\n", data);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void 	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list	*list;

	list = begin_list;
	while (list)
	{
		if ((*cmp)(list->data, data_ref) == 0)
			(*f)(list->data);
		list = list->next;
	}
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *add;

	add = ft_create_elem(data);
	add->next = *begin_list;
	*begin_list = add;
}

t_list	*ft_list_push_params(int ac, char **av)
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
	void 			*data;
	void 			(*f)(void *);
	int 			(*cmp)();

	f = &ft_print;
	data = "titi";
	cmp = ft_strcmp;
	list = ft_list_push_params(argc, argv);
    ft_list_foreach_if(list, f, data, cmp);

	return 0;
}
