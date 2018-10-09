#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int	nb;
	int	n;

	n = 2;
	nb = 0;
	if (ac == 2)
	{
		nb = atoi(av[1]);
		if (nb == 1)
			printf("1");
		else
		{
			while (nb != 1)
			{
				while (nb % n == 0)
				{
					nb /= n;
					printf("%d", n);
					if (nb != 1)
						printf("*");
				}
				n++;
			}
		}
	}
	printf("\n");
	return (0);
}
