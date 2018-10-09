#include "bsq.h"

// void	ft_file_len(char *filename, t_coord *pt)
// {
// 	int		n;
// 	int		file;
// 	int		i;
// 	char	buf[2];
//
// 	n = 0;
// 	i = 0;
// 	if (!(buf = (char*)malloc(sizeof(char) + 1)))
// 		return;
// 	buf[1] = '\0';
// 	file = open(filename, O_RDONLY);
// 	while (*buf != '\n')
// 		read(file, buf, 2);
// 	read(file, buf, 2);
// 	while(read(file, buf, 2) != 0)
// 	{
// 		// if (buf[0] == '\n')
// 		// {
// 		// 	n++;
// 		// 	printf("n = %d\n", n);
// 		// 	//read(file, buf, 1);
// 		// 	printf("col = %d\n", pt->nbcol);
// 		// 	//if (i != pt->nbcol)
// 		// 		//return;
// 		// 	//i = 0;
// 		// }
// 		printf("buf = %s\n", buf);
// 		//i++;
// 		read(file, buf, 2);
// 	}
// 	close(file);
// 	pt->nblines = (n);
// 	//printf("nb lignes = %d\n", pt->nblines);
// 	//printf("col = %d\n", pt->nbcol);
// 	//printf("lin = %d\n", pt->nblines);
// 	free(buf);
// }

int		ft_file_len(char *filename, t_coord *pt)
{
	int		file;
	char	*buf;
	int		i;
	int		n;

	n = 0;
	pt->size_theo = (pt->nblines) * (pt->nbcol);
	printf("nblines = %d\n", pt->nblines);
	printf("nbcol = %d\n", pt->nbcol);
	printf("size_theo = %d\n", pt->size_theo);
	if (!(buf = (char*)malloc(pt->size_theo)))
		return (0);
	file = open(filename, O_RDONLY);
	if (file < 0)
		return (0);
	while (read(file, buf, pt->size_theo) != 0 && n != pt->nblines)
	{
		read(file, buf, pt->size_theo);
		i = 0;
		while(buf[i] != '\0')
		{
			if (buf[i] == '\n')
				n++;
			i++;
		}
	}
	if (read(file, buf, pt->size_theo) == 0 || n != pt->nblines)
		return (0);
	else
		return (1);
}
