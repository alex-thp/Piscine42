#include "ft_list.h"

void    ft_list_clear(t_list **begin_list)
{
    t_list *list;
    t_list *tmp;

    list = *begin_list;
    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
    *begin_list = NULL;
}

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

int main(int argc, char **argv) {

    char *s2 = malloc(1);
    *s2 = '1';
    free(s2);

    char *s1 = malloc(1);
    printf("%c\n", *s1);
    printf("%p\n%p\n", s1, s2);
	t_list *list = ft_list_push_params(argc, argv);
    ft_list_clear(&list);

	return 0;
}
