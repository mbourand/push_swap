/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:08:36 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:32:53 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "stack.h"
#include "args.h"

static int		swap_operation(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return (TRUE);
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
	return (TRUE);
}

static int		push_operation(t_stack *src, t_stack *dest)
{
	if (src->size == 0)
		return (TRUE);
	push(dest, src->arr[0]);
	erase(src, 0);
	return (TRUE);
}

static int		rotate_operation(t_stack *stack)
{
	size_t	i;
	int		tmp;

	if (stack->size < 2)
		return (TRUE);
	tmp = stack->arr[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->size - 1] = tmp;
	return (TRUE);
}

static int		reverse_rotate_operation(t_stack *stack)
{
	int		i;
	int		tmp;

	if (stack->size < 2)
		return (TRUE);
	tmp = stack->arr[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
	return (TRUE);
}
