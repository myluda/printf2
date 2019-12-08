#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H


# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int             ft_printf(const char *str1, ...);
char		    *ft_utoa(unsigned int n);
int		        ft_tolower(int c);
int		        ft_toupper(int c);
int		        ft_strlen(char *str);
char            *ft_hexa(unsigned long long c);
char	        *ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
void            ft_putstr(char *str,int *indice);
void            ft_putchar(char c,int *indice);
char            *ft_hexa_upper(unsigned long long c);
int				ft_atoi(const char *str);
size_t		    ft_strlcat(char *dst, const char *src, size_t size);
char		    *ft_strdup(const char *src);
int		        ft_isalpha(int str);
void            ft_putstr_c(char *str,int *indice);
char            *ft_hexa_p(unsigned long long c);
char            *ft_strcpyy(const char *s1, char *s2);
void            ft_putstr_r(char *str,int *indice);


#endif
