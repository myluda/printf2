/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:08:38 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/06 20:08:44 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_putstr_r(char *str,int *indice)
{
	int i;

	i = 0;
	write(1,"\0",1);
	*indice = *indice + 1;
	while(str[i + 1] != '\0')
	{
		write(1,&str[i],1);
		i++;
		*indice = *indice + 1;
	}
}
