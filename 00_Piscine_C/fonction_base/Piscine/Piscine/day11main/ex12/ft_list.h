/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:36:09 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/23 17:36:31 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_list
{
	void *data;
	struct s_list *next;
}				t_list;

t_list			*ft_create_elem(void *data);
void			ft_list_push_back(t_list **begin_list, void *data);


#endif
