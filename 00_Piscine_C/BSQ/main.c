#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

//RECUPERATION DES PARAMETRES

char    *ft_strcat(char *dest, char *src);
char    *ft_realloc(char *tab, int old_size, int new_size);
int        ft_strlen(char *str);
int        ft_unsigned_atoi(char *str);
void    ft_parse_line(char *str);

void    main(void)
{
    int        fd;
    int        i;
    char    *buf;
    char    *tab;

    i = 1;
    if (!(tab = (char*)malloc(sizeof(char) + 1)))
        exit (0);
    if (!(buf = (char*)malloc(sizeof(char) + 1)))
        exit (0);
    fd = open(“example”, O_RDONLY);
    if (fd < 0)
        exit (0);
    while (*buf != ‘\n’)
    {
        ft_strcat(tab, buf);
        ft_realloc(tab, i, (i + 1));
        read(fd, buf, 1);
        i++;
    }
    printf("%s\n", tab);
    ft_parse_line(tab);
    close(fd);
    exit (0);
}

void    ft_parse_line(char *str)
{
    int        len;
    int        nline;
    char    print;
    char    full;
    char    empty;

    len = ft_strlen(str);
    print = str[len - 1];
    full = str[len - 2];
    empty = str[len - 3];
    printf("Caractere d’ecriture : %c\n", print);
    printf("Caractere plein : %c\n", full);
    printf("Caractere vide : %c\n", empty);
    nline = ft_unsigned_atoi(str);
    printf("Nombre de ligne : %d\n", nline);
}

//LECTURE

void		ft_readmap(char *filename, t_coord *pt)
{
	int i;
	int j;
	int fd;
	char *buf;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(0);
	if (!(buf = (char*)malloc(sizeof(char) + 1)))
		exit(0);
	i = 0;
	//lire le tableau pour **intab
	//while (buf )
}

//CONVERTION

int			ft_params_convert(char a, char b)
{
	int cpt;
	int *tab;

	cpt = 0;
	if (!(tab = (int *)malloc(sizeof(int) * pt->nbcol)))
		return;
	while (pt->tab[n])
	{
		if (pt->tab[n][cpt] == a || pt->tab[n][cpt] == b)
		{
			if (pt->tab[n][cpt] == a)
				tab[cpt] = pt->tab[n][cpt] - a + 11;
			else
				tab[cpt] = pt->tab[n][cpt] - b + 10;
			cpt++;
		}
		else
			exit(0);
	}
	tab[cpt] = 0;
	pt->intab[n] = tab;
	free(tab);
}

//COMPARAISON

void 	ft_maj_max(int *line, int length, int line_number, t_coord *pt)
{
	int max;
	int i;

	i = 0;
	while (i < length)
	{
		if (line[i] > pt->max)
			max = line [i];
		i++;
	}
	pt->x = i;
	pt->y = line_number;
	pt->max = max;
}

int		ft_compare(int *line1, int *line2, int index)
{
	int min;

	min = line2[index - 1];
	if (line1[index - 1] < min)
		min = line1[index - 1];
	if (line1[index] < min)
		min = line1[index];
	min ++;
	return (min);
}

void	ft_algorithme(t_coord *pt, int line_number)
{
	int i;
	int *line1;
	int *line2;
	int	length;

	line1 = pt->intab[0];
	line2 = pt->intab[1];
	i = 1;
	length = pt->nbcol;
	while (i < length)
	{
		if (line2[i] != 0)
			line2[i] = ft_compare(line1, line2, i);
		i++;
	}
	ft_bsq_get_max(line2, length, line_number, pt);
	pt->intab[1] = line2;
}

//INCREMENTATION STRUCTURE



//AFFICHAGE

void	ft_condition(t_coord *pt, int fd)
{
	int		i;
	int		j;
	char	buffer[1];

	i = 1;
	while (i < pt->nblines)
	{
		j = 1;
		while (j < pt->nbcol)
		{
			read(fd, buffer, 1);
			if (i <= pt->y && i >= (pt->y - pt->max + 1) && j <= pt->x
					&& j >= (pt->x - pt->max + 1))
				ft_putchar_out(pt->full, 1);
			else
				ft_putstr_out(buffer, 1);
			j++;
		}
		ft_putchar_out('\n', 1);
		i++;
	}
}

void	ft_writemap(char *av, t_coord *pt)
{
	int		fd;
	char	buffer[1];

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(2, "ERREUR\n", 7);
		return;
	}
	while (buffer[0] != '\n')
		read(fd, buffer, 1);
	read(fd, buffer, 1);
	ft_condition(pt, fd);
}
