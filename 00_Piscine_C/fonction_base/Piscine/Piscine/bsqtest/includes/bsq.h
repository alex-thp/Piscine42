/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:56:23 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/25 13:56:31 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct	s_coord
{
	int		x;
	int		y;
	int		max;
	int		nblines;
	int		nbcol;
	int		deadline;
	int		size_theo;
	char	empty;
	char	full;
	char	write;
	int		**intab;
	char	**tab;
}				t_coord;

void			ft_putchar_out(char c, int output);
void			ft_putstr_out(char *str, int output);
void			ft_putnbr(int nb);
void			ft_sinit(t_coord *pt);
void			ft_tournante(char *av, t_coord *pt);
void			ft_condition(t_coord *pt, int fd);
void			ft_writetab(char *av, t_coord *pt);
void			ft_charconv(t_coord *pt, char a, char b, int n);
void			ft_pre_char_read(char *str, t_coord *pt);
void			ft_double_line(t_coord *pt, char *filename);
void			ft_double_line_fill(int file, char *buf, char **tab, t_coord *pt);
void 			ft_bsq_get_max(int *line, int length, int line_number, t_coord *pt);
void			ft_first_line_read(char *str, t_coord *pt);
int				ft_parse_first_char(char *str);
int				ft_strlen(char *str);
int				ft_unsigned_atoi(char *str);
int				ft_file_len(char *filename, t_coord *pt);
int				ft_bsq_cmp(int *line1, int *line2, int index);
void			ft_bsq_change_line(t_coord *pt, int line_number);
char			*ft_strdup(char *src);
char			*ft_realloc(char *tab, int old_size, int new_size);
char			*ft_first_char_read(char *str);
char			*ft_strcat(char *dest, char *src);
char			**ft_double_fill(int file, char **tab);

#endif
