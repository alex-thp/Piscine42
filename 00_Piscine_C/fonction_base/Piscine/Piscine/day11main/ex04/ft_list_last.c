/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 23:29:26 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/23 23:29:29 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

t_list	*ft_create_elem(void *data)
{
	t_list *tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (0);
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}
void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *add;

	add = ft_create_elem(data);
	add->next = *begin_list;
	*begin_list = add;
}


int main(int argc, char const *argv[]) {

	t_list *list = NULL;
	t_list *result = NULL;


	// ft_list_push_front(&list, "toto");
	// ft_list_push_front(&list, "toto2");
	result = ft_list_last(list);
	if (result)
	printf("%s\n", result->data);
	return 1;


	return 0;
}
