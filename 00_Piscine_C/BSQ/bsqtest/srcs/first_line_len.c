#include "bsq.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_pre_char_read(char *str, t_coord *pt)
{
	int		file;
	char	*buf;
	int		i;
	char	*tab;

	i = 0;
	if (!(buf = malloc(sizeof(char) + 1)))
		return;
	if (!(tab = (char*)malloc(sizeof(char) + 1)))
		return;
	file = open(str, O_RDONLY);
	if (file < 0)
		ft_putstr_out("map error\n Can't open file\n", 2);
	while (*buf != '\n')
	{
		read(file, buf, 1);
		ft_strcat(tab, buf);
		ft_realloc(tab, i, (i + 1));
		i++;
	}
	close(file);
	pt->nbcol = ft_strlen(tab);
	free(tab);
}
