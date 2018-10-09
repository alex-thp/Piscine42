#include "bsq.h"

char	*ft_strdup(char *src)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * ft_strlen(src))))
		return (0);
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	ft_init_struct(t_map *pt)
{
	int i;

	i = 0;
	if (!(pt = (t_map *)malloc(sizeof(t_map))))
		exit (0);
	pt->x = 0;
	pt->y = 0;
	pt->ncol = 0;
	pt->nline = 0;
	pt->max = 0;
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	t_map	pt;

	i = 1;
	while (i < ac)
	{
		pt.filename = av[i];
		ft_init_struct(&pt);
		ft_read_params(&pt);
		ft_first_line_read(&pt, i);
		j = 0;
		while (j < pt.nline)
		{
			printf("%d\n", pt.nline);
			printf("%d\n", pt.intab[i][j]);
			j++;
		}
		printf("FLAG");
		i++;
	}
	i = 0;
	return (0);
}
