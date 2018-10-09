#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct	s_map
{
	char	print;
	char	empty;
	char	full;
	char	*filename;
	int		x;
	int		y;
	int		ncol;
	int		nline;
	int		max;
	int		**intab;
}				t_map;


void			ft_putchar(char c, int out);
void			ft_putnbr(int nb);
void			ft_init_struct(t_map *pt);
void    		ft_parse_line(char *str, t_map *pt);
void			ft_line_conv(char *str, t_map *pt, int n);
char			*ft_strdup(char *src);
char			*ft_strcat(char *dest, char *src);
char			*ft_realloc(char *tab, int old_size, int new_size);
int				ft_first_line_read(t_map *pt, int n);
int				ft_read_params(t_map *pt);
int				ft_strlen(char *str);
int				ft_unsigned_atoi(char *str);

#endif
