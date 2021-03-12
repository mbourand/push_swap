/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:19:23 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:37:41 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "utils.h"
#include <stdio.h>

void		errndie(char *str)
{
	ft_putstr(str, 2);
	exit(1);
}

void		ft_bzero(void *ptr, size_t size)
{
	size_t			i;
	unsigned char	*cast;

	cast = (unsigned char*)ptr;
	i = 0;
	while (i < size)
	{
		cast[i] = 0;
		i++;
	}
}

int			freenret(void *ptr, int ret)
{
	if (ptr)
		free(ptr);
	return (ret);
}

int			ft_min(int a, int b)
{
	return (a < b ? a : b);
}
