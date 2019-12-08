/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:58:38 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/21 00:14:40 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_strrev(char *str)
{
	int		i;
	int		k;
	int		j;
	char	temp;

	i = 1;
	while (str[i] != '\0')
	{
		i++;
	}
	k = 1;
	j = i - 1;
	while (k < j)
	{
		temp = str[k];
		str[k] = str[j];
		str[j] = temp;
		k++;
		j--;
	}
	return (str);
}

static char	*ft_strrev1(char *str)
{
	int		i;
	int		k;
	int		j;
	char	temp;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	k = 0;
	j = i - 1;
	while (k < j)
	{
		temp = str[k];
		str[k] = str[j];
		str[j] = temp;
		k++;
		j--;
	}
	return (str);
}

static int	ft_length(int n)
{
	int i;
	int s;

	s = n;
	i = 0;
	while (s != 0)
	{
		s = s / 10;
		i++;
	}
	return (i);
}

static char	*ft_stock(int n, char *dest)
{
	unsigned int	f;
	int				i;
	char			s;

	i = 0;
	f = n;
	if (n < 0)
	{
		i = 1;
		dest[0] = '-';
		f = f * (-1);
	}
	while (f != 0)
	{
		s = f % 10 + '0';
		f = f / 10;
		dest[i] = s;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*dest;
	char	*tmp;

	len = ft_length(n);
	if (n < 0)
	{
		if (!(dest = malloc(sizeof(char) * (len + 2))))
			return (0);
	}
	else if (n == 0)
	{
		if (!(dest = malloc(sizeof(char) * 2)))
			return (0);
		dest[0] = '0';
		dest[1] = '\0';
		return (dest);
	}
	else
	{
		if (!(dest = malloc(sizeof(char) * (len + 1))))
			return (0);
	}
	dest = ft_stock(n, dest);
	tmp = dest;
	free(tmp);
	return (n < 0 ? ft_strrev(dest) : ft_strrev1(dest));
}
