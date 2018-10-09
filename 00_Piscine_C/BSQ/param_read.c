#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

char    *ft_strcat(char *dest, char *src);
char    *ft_realloc(char *tab, int old_size, int new_size);
int        ft_strlen(char *str);
int        ft_unsigned_atoi(char *str);
void    ft_parse_line(char *str);

void    main(void)
{
    int        fd;
    int        i;
    char    *buf;
    char    *tab;

    i = 1;
    if (!(tab = (char*)malloc(sizeof(char) + 1)))
        exit (0);
    if (!(buf = (char*)malloc(sizeof(char) + 1)))
        exit (0);
    fd = open(“example”, O_RDONLY);
    if (fd < 0)
        exit (0);
    while (*buf != ‘\n’)
    {
        ft_strcat(tab, buf);
        ft_realloc(tab, i, (i + 1));
        read(fd, buf, 1);
        i++;
    }
    printf("%s\n", tab);
    ft_parse_line(tab);
    close(fd);
    exit (0);
}

void    ft_parse_line(char *str)
{
    int        len;
    int        nline;
    char    print;
    char    full;
    char    empty;

    len = ft_strlen(str);
    print = str[len - 1];
    full = str[len - 2];
    empty = str[len - 3];
    printf("Caractere d’ecriture : %c\n", print);
    printf("Caractere plein : %c\n", full);
    printf("Caractere vide : %c\n", empty);
    nline = ft_unsigned_atoi(str);
    printf("Nombre de ligne : %d\n", nline);
}
