#include "bsq.h"

void	ft_file_len(char *filename, t_coord *pt)
{
	int		n;
	int		file;
	int		i;
	char	*buf;

	n = 0;
	i = 0;
	if (!(buf = (char*)malloc(sizeof(char) + 1)))
		return;
	file = open(filename, O_RDONLY);
	while(buf[0] != '\0')
	{
		if (buf[0] == '\n')
		{
			if (i != pt->nbcol)
				return;
			n++;
			i = 0;
		}
		i++;
		read(file, buf, 1);
	}
	close(file);
	pt->nblines = (n - 1);
	free(buf);
}
