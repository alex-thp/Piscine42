#include "bsq.h"

char	*ft_realloc(char *tab, int old_size, int new_size)
{
	char	*tab2;
	int		i;
	if (!(tab2 = (char*)malloc(sizeof(tab))))
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		tab2[i] = tab[i];
		i++;
	}
	free(tab);
	if (!(tab = (char*)malloc(sizeof(char) * new_size)))
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		tab[i] = tab2[i];
		i++;
	}
	free(tab2);
	return (tab);
}

int		ft_first_line_read(t_map *pt, int n)
{
    int        fd;
    int        i;
    char    *buf;
    char    *tab;

    i = 0;
    if (!(tab = (char*)malloc(sizeof(char) + 1)))
        return (0);
    if (!(buf = (char*)malloc(sizeof(char) + 1)))
        return (0);
    fd = open(pt->filename, O_RDONLY);
    if (fd < 0)
        return (0);
    while (i <= n)
	{
		while(*buf != '\n')
			read(fd, buf, 1);
		read(fd, buf, 1);
		i++;
	}
	i = 1;
	while (*buf != '\n')
    {
		printf("%s\n", tab);
        ft_strcat(tab, buf);
        ft_realloc(tab, i, (i + 1));
        read(fd, buf, 1);
        i++;
    }
    ft_parse_line(tab, pt);
    if (!(pt->intab = (int**)malloc(sizeof(int*) * pt->nline + 1)))
        return (0);
    ft_line_conv(tab, pt, 0);
    close(fd);
    return (0);
}
