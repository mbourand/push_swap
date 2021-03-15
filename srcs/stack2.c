/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:13:31 by user42            #+#    #+#             */
/*   Updated: 2021/03/15 15:20:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	j;

	i = 0;
	ft_putstr("|     a     |     b     |\n", 1);
	ft_putstr("|-----------|-----------|\n", 1);
	while (i < a->size + b->size)
	{
		ft_putstr("|", 1);
		j = 0;
		if (i < a->size)
			ft_putnbr(a->arr[i]);
		while (j++ < 11 - (i < a->size ? ft_numlen(a->arr[i], 10) : 0))
			ft_putstr(" ", 1);
		ft_putstr("|", 1);
		j = 0;
		if (i < b->size)
			ft_putnbr(b->arr[i]);
		while (j++ < 11 - (i < b->size ? ft_numlen(b->arr[i], 10) : 0))
			ft_putstr(" ", 1);
		ft_putstr("|\n", 1);
		i++;
	}
	ft_putstr("|-----------------------|\n", 1);
}

int		is_sorted(t_stack *stack)
{
	size_t i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] >= stack->arr[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
