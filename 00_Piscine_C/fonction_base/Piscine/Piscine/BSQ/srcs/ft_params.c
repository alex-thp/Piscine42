#include "bsq.h"

int		ft_unsigned_atoi(char *str)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (str[i + 3] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb);
}

void    ft_parse_line(char *str, t_map *pt)
{
   int		len;

   len = ft_strlen(str);
   pt->print = str[len - 1];
   pt->full = str[len - 2];
   pt->empty = str[len - 3];
   pt->nline = ft_unsigned_atoi(str);
}

int		ft_read_params(t_map *pt)
{
	int		fd;
	int		i;
	char	*buf;
	char	*tab;

	i = 1;
	if (!(tab = (char*)malloc(sizeof(char) + 1)))
		return (0);
	if (!(buf = (char*)malloc(sizeof(char) + 1)))
		return (0);
	fd = open(pt->filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (*buf != '\n')
	{
		ft_strcat(tab, buf);
		ft_realloc(tab, i, (i + 1));
		read(fd, buf, 1);
		i++;
	}
	ft_parse_line(tab, pt);
	if (!(pt->intab = (int**)malloc(sizeof(int*) * pt->nline + 1)))
		return (0);
	close(fd);
	return (0);
}
