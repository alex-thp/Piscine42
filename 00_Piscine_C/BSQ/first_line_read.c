#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

typedef	struct	s_map
{
	char	print;
	char	empty;
	char	full;
	int		x;
	int		y;
	int		ncol;
	int		nline;
	int		max;
	int		**intab;
	char	*filename;
}				t_map;

char	*ft_strcat(char *dest, char *src);
char	*ft_realloc(char *tab, int old_size, int new_size);
int		ft_strlen(char *str);
int		ft_unsigned_atoi(char *str);

void    ft_parse_line(char *str, t_map *pt)
{
   int		len;
   int		nline;
   char		print;
   char		full;
   char		empty;

   len = ft_strlen(str);
   pt->print = str[len - 1];
   pt->full = str[len - 2];
   pt->empty = str[len - 3];
   printf("Caractere d’ecriture : %c\n", print);
   printf("Caractere plein : %c\n", full);
   printf("Caractere vide : %c\n", empty);
   pt->nline = ft_unsigned_atoi(str);
   printf("Nombre de ligne : %d\n", nline);
}

void	ft_line_conv(char *str, t_map *pt, int n)
{
	int cpt;

	cpt = 0;
	while (cpt < pt->ncol)
	{
		if (pt->intab[n][cpt] == pt->full || pt->intab[n][cpt] == pt->empty)
		{
			if (pt->intab[n][cpt] == pt->full)
				pt->intab[n][cpt] = str[cpt] - pt->full + 1;
			else
				pt->intab[n][cpt] = str[cpt] - pt->empty + 0;
			cpt++;
		}
		else
			exit (0);
	}
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

int		ft_first_line_read(t_map *pt)
{
	int        fd;
	int        i;
	char    *buf;
	char    *tab;

	i = 1;
	if (!(tab = (char*)malloc(sizeof(char) + 1)))
		return (0);
	if (!(buf = (char*)malloc(sizeof(char) + 1)))
		return (0);
	fd = open(pt->filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (*buf != '\n')
		read(fd, buf, 1);
	read(fd, buf, 1);
	while (*buf != '\n')
	{
		ft_strcat(tab, buf);
		ft_realloc(tab, i, (i + 1));
		read(fd, buf, 1);
		i++;
	}
	ft_parse_line(tab, pt);
	if (!(pt->intab = (int**)malloc(sizeof(int*) * pt->ncol * pt->nline)))
		return (0);
	ft_line_conv(tab, pt, 0);	
	printf("%d\n", ft_strlen(tab));
	close(fd);
	return (0);
}


int		main(int ac, char **av)
{
	int		i;
	int		j;
	t_map	*pt;

	i = 1;
	while (i < ac)
	{
		ft_init_struct(pt);
		if (!(pt->filename = (char*)malloc(sizeof(char) * ft_strlen(av[i]))))
			exit (0);
		pt->filename = av[i];
		ft_first_line_read(pt);
		i++;
	}
	i = 0;
	while (pt->intab[0])
	{
		printf("%d\n", pt->intab[0][i]);
		i++;
	}
}
