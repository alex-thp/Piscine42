/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 10:57:41 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/27 17:43:49 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

int 	main(int argc, char **argv)
{
	t_list 			*list;
	void 			*data;
	int 			(*cmp)();

	data = "titi";
	cmp = &ft_strcmp;
	list = ft_list_push_params(argc, argv);
    ft_list_remove_if(list, data, cmp);
	printf("%d\n", ft_list_size(list));

	return 0;
}
