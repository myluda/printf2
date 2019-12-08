/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:51 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/21 22:07:35 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*s12;

	k = 0;
	i = 0;
	if (!(s1))
		return (NULL);
		
	if (!(s12 = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)))
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		s12[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		s12[i] = s2[k];
		i++;
		k++;
	}
	s12[i] = '\0';
	return (s12);
}
