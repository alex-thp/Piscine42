#include "bsq.h"

void	ft_line_conv(char *str, t_map *pt, int n)
{
	int cpt;

	cpt = 0;
	if (!(pt->intab[n] = (int*)malloc(sizeof(int) * pt->ncol)))
		exit (0);
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
