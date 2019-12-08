/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:19:24 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/07 05:13:08 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int g_widthh;
int g_preci;
int g_flag;
int g_count;
int g_indice;
int g_point;

int			ft_etoile_width(char **str, int i, va_list arg)
{
	int		s;

	s = va_arg(arg, int);
	if ((*str)[i] == '*')
	{
		g_widthh = s;
	}
	return (g_widthh);
}

void		ft_etoile_preci(char **str, int i, va_list arg)
{
	int		s;

	s = va_arg(arg, int);
	if ((*str)[i + 1] == '*')
	{
		if (s < 0)
		{
			s = -2;
		}
		g_preci = s;
	}
}

char		*ft_print_flags_minus0(char *s, int *preci1, int i, int k)
{
	if (g_flag == 2 && ((*preci1 == 0 && g_point == 0)
				|| (*preci1 == -2 && g_point == 1)))
	{
		while (s[k] != '-' && s[k] != '\0')
			k++;
		if (g_point != 1 || g_point == 1)
		{
			while (s[i] == ' ')
				s[i++] = '0';
			i = 0;
			while (s[i] != '0' && s[i] != '\0')
			{
				i++;
				if (s[i] == '-')
					break ;
			}
			if (s[i] == '0' && s[k] == '-')
			{
				s[i] = '-';
				s[k] = '0';
			}
		}
	}
	return (s);
}

char		*ft_print_flag_minus1(char *s, int i, int k)
{
	int		len;
	char	temp;
	int		f;

	if (g_flag == 1)
	{
		while (s[i] == ' ')
			i++;
		len = i;
		while (s[len] != '\0')
			len++;
		f = len - i;
		while (f > 0)
		{
			temp = s[k];
			s[k] = s[i];
			s[i] = temp;
			i++;
			k++;
			f--;
		}
	}
	return (s);
}

char		*ft_print_flags_minus(char *s, int *preci1)
{
	int		k;
	int		i;

	i = 0;
	k = 0;
	if (g_flag == 1)
		return (ft_print_flag_minus1(s, i, k));
	else if (g_flag == 2 && ((*preci1 == 0 && g_point == 0)
				|| (*preci1 == -2 && g_point == 1)))
		return (ft_print_flags_minus0(s, preci1, i, k));
	return (s);
}

int			leng(int c)
{
	int count;

	count = 0;
	while (c != 0)
	{
		c = c / 10;
		count++;
	}
	return (count);
}

int			flags(char *str, int i)
{
	if (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '-')
			return (1);
		return (2);
	}
	return (0);
}

int			width(char *str, int *i)
{
	int		width;

	while (str[*i] == '-' || str[*i] == '0')
		*i = *i + 1;
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		width = ft_atoi(&str[*i]);
		return (width);
	}
	return (0);
}

int			precision_leng(char *str, int *i)
{
	int		precision;

	while (str[*i + 1] == '0')
	{
		*i = *i + 1;
	}
	precision = ft_atoi(&str[*i + 1]);
	return (leng(precision));
}

int			precision(char *str, int *i)
{
	int		precision;

	if (str[*i] == '.')
	{
		g_point = 1;
		while (str[*i + 1] == '0')
			*i = *i + 1;
		if (str[*i + 1] >= '0' && str[*i + 1] <= '9')
			precision = ft_atoi(&str[*i + 1]);
		else
			precision = 0;
		return (precision);
	}
	g_point = 0;
	return (0);
}

int			ft_strrev_minus1(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '-' && str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strrev_minus(char *str, int *preci1)
{
	int		k;
	int		i;
	int		j;
	char	temp;

	k = 0;
	i = ft_strrev_minus1(str);
	j = i;
	while (str[j] != '\0')
		j++;
	j = j - i;
	while (str[k] == ' ')
		k++;
	if (str[i] == '\0')
		return (str);
	if (str[i] == '-' && (*preci1 >= j))
	{
		temp = str[i];
		str[i] = str[k - 1];
		str[k - 1] = temp;
		str[i] = '0';
		if (str[0] == '0')
			str = ft_strjoin("-", str);
	}
	return (str);
}

char		*ft_print_zero(char *s, int count)
{
	char	*str;

	str = malloc(sizeof(char) * g_preci + 1);
	while (count >= 0)
	{
		str[g_preci--] = s[count--];
	}
	while (g_preci >= 0)
	{
		str[g_preci--] = '0';
	}
	return (str);
}

char		*ft_print_spaces(char *s, int *preci1, int i, char *str1)
{
	char	*str;
	int		d;
	int		remaind;
		
	remaind = g_widthh;
	d = ft_strlen(s);
	str = malloc(sizeof(char) * g_widthh + 1);
	if (d > g_widthh)
		g_widthh = d;
	while (d >= 0)
	{
		str[g_widthh] = s[d];
		d--;
		g_widthh--;
	}
	while (g_widthh >= 0)
		str[g_widthh--] = ' ';
	str[g_widthh] = ' ';
	if (str[remaind - 1] == '0' && (str[remaind - 2] < '0'
		|| str[remaind - 2] > '9') && *preci1 == 0 && str1[i] == '.')
		str[remaind - 1] = ' ';
	str = ft_strrev_minus(str, preci1);
	str = ft_print_flags_minus(str, preci1);
	return (str);
}

char		*ft_only_zero(char *s)
{
	int		d;
	int		i;
	char	*str;

	i = 0;
	d = ft_strlen(s);
	str = malloc(sizeof(char));
	if (s[0] == '0' && s[1] == '\0')
	{
		str[0] = '0';
	}
	str[1] = '\0';
	return (str);
}

char		*ft_print_spaces_zeroes(char *s, char *str, int i)
{
	int		d;

	d = ft_strlen(s);
	if ((str[i] == '.' || str[i - 1] == '.'))
	{
		s[0] = '\0';
	}
	else
	{
		s[0] = '0';
		s[1] = '\0';
	}
	return (s);
}

int			ft_indices0(char **str, va_list arg, int i)
{
	if ((*str)[i + 1] == '*' && (*str)[i] == '.')
	{
		g_point = 1;
		ft_etoile_preci(str, i, arg);
		i = i + 2;
	}
	else
	{
		g_preci = precision(*str, &i);
		if (g_preci != 0)
			i = i + precision_leng(*str, &i) + 1;
		else if (g_point == 1)
			i++;
	}
	return (i);
}

int			ft_indices(char **str, int *flag, va_list arg, int i)
{
	i++;
	*flag = flags(*str, i);
	if (((*str)[i] == '-') || ((*str)[i] == '0'))
	{
		while (((*str)[i] == '-') || ((*str)[i] == '0'))
			i = i + 1;
	}
	if ((*str)[i] == '*')
	{
		g_widthh = ft_etoile_width(str, i, arg);
		if (g_widthh < 0)
		{
			g_widthh = g_widthh * -1;
			*flag = 1;
		}
		i++;
	}
	else
	{
		g_widthh = width(*str, &i);
		if (g_widthh != 0)
			i = i + leng(g_widthh);
	}
	i = ft_indices0(str, arg, i);
	return (i);
}

char		*ft_print_preci(char *s, int preci1)
{
	int		i;
	int		k;
	char	*str;
	char	*tmp;

	i = 0;
	str = malloc(sizeof(char) * preci1 + g_count + 1);
	k = preci1 + g_count;
	while (k > 0)
	{
		str[i] = s[i];
		i++;
		k--;
	}
	str[i] = '\0';
	tmp = str;
	free(tmp);
	return (str);
}

char		*print_preci_s(char *s)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = malloc(sizeof(char) * g_preci + 1);
	while (g_preci > 0)
	{
		str[i] = s[i];
		g_preci--;
		i++;
	}
	str[i] = '\0';
	tmp = str;
	free(tmp);
	return (str);
}

int			place(char *str, int i)
{
	int		c;

	c = 0;
	if (str[i] == '*')
		c = 1;
	while (str[i] != '%')
	{
		i--;
		if (str[i] == '%')
		{
			return (i);
		}
	}
	return (i);
}

char		*ft_pourcent_print(char *s, int preci1, char *str, int i)
{
	int		c;
	int		d;

	d = 0;
	c = 0;
	if ((g_preci == -2 && g_flag != 2) || (str[i] == '%' && g_flag == 0)
			|| (str[i] == 'c' && s[0] == '\0')
				|| ((g_point == 0 && g_widthh && preci1 == 0) && str[i] == 's'))
		s = ft_print_spaces(s, &preci1, i, str);
	else if (str[i] == '%' && g_flag == 1)
	{
		s = ft_print_spaces(s, &preci1, i, str);
		d = ft_strlen(s);
		s[d - 1] = ' ';
		s[0] = '%';
	}
	else if (str[i] == '%' && g_flag == 2)
	{
		s = ft_print_spaces(s, &preci1, i, str);
		while (s[c] == ' ')
			s[c++] = '0';
	}
	return (s);
}

char		*ft_pourcent_print1(char *s, int preci1, char *str, int i)
{
	char	*tmp;

	if (str[i] == 'c' && s[0] == '\0' && !g_widthh)
	{
		g_indice = 1;
		s = ft_print_spaces(s, &preci1, i, str);
		tmp = s;
		free(tmp);
		return (s);
	}
	else if ((g_preci <= g_widthh && str[i] == 's' && g_point == 1)
		|| ((g_preci > g_widthh) && str[i] == 's' && s[0] != '\0'))
	{
		s = print_preci_s(s);
		s = ft_print_spaces(s, &preci1, i, str);
		tmp = s;
		free(tmp);
		return (s);
	}
	else if (s[0] == '\0' && str[i] == 's' && g_widthh == 0)
		return (ft_strdup(""));
	return (0);
}

char		*ft_pourcent_print2(char *s, int preci1, char *str, int i)
{
	int d;
	int c;

	c = 0;
	d = 0;
	if ((s[0] == '0' && s[1] == '\0')
		&& g_point == 1 && g_preci == 0 && g_flag == 1)
	{
		d = g_widthh;
		s = ft_print_spaces(s, &preci1, i, str);
		c = precision_leng(str, &i);
		if ((c != 0 || g_widthh) && s[0] != '0')
			s[ft_strlen(s) - 1] = ' ';
		else if (d == 1 && c == 0)
		{
			s[0] = ' ';
			s[1] = '\0';
		}
		else
			s[0] = ' ';
		return (s);
	}
	return (s);
}

char		*ft_pourcent_print3(char *s, int preci1, char *str, int i)
{
	int		d;
	int		c;

	c = 0;
	d = 0;
	if ((s[0] == '0' && s[1] == '\0') && g_point == 1 && g_preci == 0)
	{
		d = g_widthh;
		s = ft_print_spaces(s, &preci1, i, str);
		c = precision_leng(str, &i);
		if ((c != 0 || g_widthh) && s[0] != '0')
			s[ft_strlen(s) - 1] = ' ';
		else if (d == 1 && c == 0)
		{
			s[0] = ' ';
			s[1] = '\0';
		}
		else
			s[0] = '\0';
		return (s);
	}
	return (0);
}

char		*ft_pourcent_print4(char *s, int preci1, char *str, int i)
{
	if (((s[0] == '0' && s[1] == '\0') ||
		(s[0] == '\0')) && g_preci == 0 && g_widthh == 0)
	{
		s = ft_print_spaces_zeroes(s, str, i);
		return (s);
	}
	else if (str[i] == 's')
	{
		preci1 = g_preci;
		s = ft_print_preci(s, preci1);
		s = ft_print_spaces(s, &preci1, i, str);
		return (s);
	}
	return (s);
}

char		*ft_pourcent_print5(char *s, int preci1, char *str, int i)
{
	if ((g_widthh > g_count) && (g_widthh > g_preci))
	{
		preci1 = g_preci;
		if (g_count > g_preci)
			g_preci = g_count;
		s = ft_print_zero(s, g_count);
		s = ft_print_spaces(s, &preci1, i, str);
	}
	else if ((g_preci >= g_count) && (g_preci >= g_widthh))
	{
		preci1 = g_preci;
		s = ft_print_zero(s, g_count);
		s = ft_strrev_minus(s, &preci1);
	}
	else if (g_point == 1
		&& (s[0] == '0' && s[1] == '\0') && (g_widthh == 0 || g_widthh == 1))
		s = ft_only_zero(s);
	else if (g_count >= g_preci && g_count > g_widthh)
		return (s);
	else if (g_count >= g_widthh)
		return (s);
	return (s);
}

char		ft_print_str1(char *s, int preci1, char *str, int i)
{
	if (((g_preci == -2 && g_flag != 2) || (str[i] == '%' && g_flag == 0)
		|| (str[i] == 'c' && s[0] == '\0') || ((g_point == 0 && g_widthh
			&& preci1 == 0) && str[i] == 's')) || (str[i] == '%' &&
				g_flag == 1) || (str[i] == '%' && g_flag == 2))
				return (1);
	else if ((str[i] == 'c' && s[0] == '\0' && !g_widthh) || 
		((g_preci <= g_widthh && str[i] == 's' && g_point == 1)
			|| ((g_preci > g_widthh) && str[i] == 's' && s[0] != '\0'))
				|| (s[0] == '\0' && str[i] == 's' && g_widthh == 0))
				return (2);
	return (0);
}
char		*ft_print_str(char *s, int preci1, char *str, int i)
{
	int		c;

	c = 0;
	if (ft_print_str1(s, preci1, str, i) == 1)
		return (ft_pourcent_print(s, preci1, str, i));
	else if (ft_print_str1(s, preci1, str, i) == 2)
		return (ft_pourcent_print1(s, preci1, str, i));
	else if ((s[0] == '0' && s[1] == '\0') && g_point == 1 && g_preci == 0 && g_flag == 1)
		return (ft_pourcent_print2(s, preci1, str, i));
	else if ((s[0] == '0' && s[1] == '\0') && g_point == 1 && g_preci == 0)
		return (ft_pourcent_print3(s, preci1, str, i));
  	else if ((((s[0] == '0' && s[1] == '\0') || (s[0] == '\0'))
    	&& g_preci == 0 && g_widthh == 0) || (str[i] == 's'))
			return (ft_pourcent_print4(s, preci1, str, i));
	else if (((g_widthh > g_count) && (g_widthh > g_preci)) ||
		((g_preci >= g_count) && (g_preci >= g_widthh))
			|| (g_point == 1 && (s[0] == '0' && s[1] == '\0') && (g_widthh == 0 || g_widthh == 1))
				|| (g_count >= g_preci && g_count > g_widthh) || (g_count >= g_widthh))
		return (ft_pourcent_print5(s, preci1, str, i));
	return (0);
}

void		pourcent_c(va_list arg, char *str, int preci1, int i)
{
	char 	*s;
	char 	*str1;

	s = malloc(sizeof(char) * 2);
	s[0] = va_arg(arg, int);
	str1 = ft_strcpyy(str1, s);
	s = ft_print_str(s, preci1, str, i);
	if ((g_point == 1 || g_point == 0) && str1[0] == '\0' && g_flag != 1)
		ft_putstr_c(s, &g_indice);
	else if (g_flag == 1 && str1[0] == '\0')
		ft_putstr_r(s, &g_indice);
	else if (s[0] == '\0')
		ft_putstr_c(s, &g_indice);
	else
		ft_putstr(s, &g_indice);
}

void		pourcent_dixu(va_list arg, char *str, int preci1, int i)
{
	char	*s;

	s = NULL;
	if (str[i] == 'd' || str[i] == 'i')
		s = ft_itoa(va_arg(arg, int));
	else if (str[i] == 'u')
		s = ft_utoa(va_arg(arg, unsigned int));
	else if (str[i] == 'x')
		s = ft_hexa(va_arg(arg, unsigned int));
	else if (str[i] == 'X')
		s = ft_hexa_upper(va_arg(arg, unsigned int));
	else if (str[i] == 's')
	{
		s = va_arg(arg, char *);
		if (s == NULL)
			s = ft_strdup("(null)");
	}
	else if (str[i] == 'p')
	{
		s = ft_strjoin("0x", (ft_hexa_p(va_arg(arg, unsigned long long))));
		if (s[2] == '0' && g_point == 1)
			s[2] = '\0';
	}
	g_count = ft_strlen(s);
	s = ft_print_str(s, preci1, str, i);
	ft_putstr(s, &g_indice);
	//free(s);
}

int			pourcent_pourcent(char *str, int preci1, int i)
{
	char	*s;

	while (str[i] == '%' && str[i - 1] == '%')
	{
		ft_putchar('%', &g_indice);
		i += (i + 2 < ft_strlen(str)) ? 2 : 1;
	}
	if (str[i] == '%')
	{
		s = malloc(sizeof(char) * 2);
		s[0] = '%';
		s[1] = '\0';
		s = ft_print_str(s, preci1, str, i++);
		ft_putstr(s, &g_indice);
	}
	if (str[i] != 's' && str[i] != 'x' && str[i] != 'X' && str[i] != 'u' 
			&& str[i] != 'p' && str[i] != 'i' &&
				str[i] != 'd' && str[i] != 'c' && str[i] != '%')
	{
		if (str[i - 1] == '%' && ((str[i] <= 'z' && str[i] >= 'a')
			|| (str[i] <= 'Z' && str[i] >= 'A') || 
				str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			ft_putchar(str[i], &g_indice);
		i = place(str, i);
	}
	return (i);
}

int		checkout_i(char *str, int i)
{
	if (str[i] == '%' && str[i + 1] == '%')
		i++;
	if (str[i] != '\0' && str[i] != '%')
		i++;
	while ((str[i] != '\0' && str[i] != '%'))
	{
		ft_putchar(str[i], &g_indice);
		i++;
	}
	return (i);
}

int		checkout_char(char *str, int i)
{
	while (str[i] != '%')
	{
		ft_putchar(str[i], &g_indice);
		i++;
	}
	return (i);
}

void		pourcent(va_list arg, char *str, int preci1, int i)
{
	if (str[i] == 'c')
		pourcent_c(arg, str, preci1, i);
	else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u'
			|| str[i] == 'x' || str[i] == 'X' || str[i] == 's' || str[i] == 'p')
		pourcent_dixu(arg, str, preci1, i);
}

int			ft_printf(const char *str1, ...)
{
	int		i;
	int		preci1;
	char	*str;
	va_list	arg;

	va_start(arg, str1);
	str = (char *)str1;
	i = 0;
	g_indice = 0;
	preci1 = 0;
	while (str[i] != '\0')
	{
		i = checkout_char(str, i);
		if (str[i] == '%')
		{
			i = ft_indices(&str, &g_flag, arg, i);
			pourcent(arg, str, preci1, i);
			if (str[i] == '%')
				i = pourcent_pourcent(str, preci1, i);
			i = checkout_i(str, i);
			if (str[i] == '\0')
				return (g_indice);
		}
	}
	return (g_indice);
}