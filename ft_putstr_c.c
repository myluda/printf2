/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 02:18:25 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/05 02:18:27 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_putstr_c(char *str,int *indice)
{
    int i;

    i = 0;
    while(str[i + 1] != '\0')
    {
        write(1,&str[i],1);
        i++;
        *indice = *indice + 1;
    }
    if(str[i + 1] == '\0' || str[i] == '\0')
    {
        write(1,"\0",1);
        *indice = *indice + 1;
    }
}