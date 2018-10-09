#include "bsq.h"

void	ft_pre_char_read(char *str, t_coord *pt)
{
	int		file;
	char	*buf;
	int		i;
	char	*tab;

	i = 1;
	if (!(buf = malloc(sizeof(char) + 1)))
		return;
	if (!(tab = (char*)malloc(sizeof(char) + 1)))
		return;
	file = open(str, O_RDONLY);
	if (file < 0)
		ft_putstr_out("map error\n Can't open file\n", 2);
	while (*buf != '\n')
		read(file, buf, 1);
	read(file, buf, 1);
	while (*buf != '\n')
	{
		read(file, buf, 1);
		ft_strcat(tab, buf);
		//printf("tab(%d) = %s\n", i, tab);
		ft_strdup(tab);
		i++;
	}
	close(file);
	pt->nbcol = ft_strlen(tab);
	printf("pre_read = %d\n", pt->nbcol);
	free(tab);
}
