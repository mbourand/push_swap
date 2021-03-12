/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:35:55 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:41:26 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <limits.h>
#include <unistd.h>

int			is_integer(char *str)
{
	size_t i;

	if (!str)
		return (FALSE);
	i = (str[0] == '+' || str[0] == '-');
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			ft_atoi(char *str, int *success)
{
	long long	ret;
	int			sign;
	size_t		i;

	if (!success)
		return (0);
	if (!str || !is_integer(str))
		return (*success = FALSE);
	ret = 0;
	sign = str[0] == '-' ? -1 : 1;
	i = (str[0] == '+' || str[0] == '-');
	while (str[i])
	{
		ret = ret * 10 + (str[i] - '0');
		if (ret * sign > INT_MAX || ret * sign < INT_MIN)
			return (*success = FALSE);
		i++;
	}
	*success = TRUE;
	return (ret * sign);
}

void		ft_putnbr(int n)
{
	unsigned int	u;
	char			c;

	u = (n < 0 ? -n : n);
	if (n < 0)
		write(1, "-", 1);
	if (u >= 10)
		ft_putnbr(u / 10);
	c = u % 10 + '0';
	write(1, &c, 1);
}

size_t		ft_numlen(int i, size_t base)
{
	size_t			res;
	unsigned int	u;

	res = i < 0 ? 2 : 1;
	u = i < 0 ? -i : i;
	while (u > base - 1)
	{
		res++;
		u /= base;
	}
	return (res);
}

int			ft_sqrt(int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (i * i >= n)
			return (i);
		i++;
	}
	return (i);
}
