/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 02:52:55 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/05 02:53:04 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    	*ft_strcpyy(const char *s1, char *s2)
{
	char	*str;
	int		i;

	str = (char *)s1;
	str = malloc(sizeof(char) * ft_strlen(s2) + 1);
	i = 0;
	while (s2[i])
	{
		str[i] = s2[i];
		i++;
	}
	str[i] = s2[i];
	return (str);
}
