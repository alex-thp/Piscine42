#include <stdlib.h>

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
