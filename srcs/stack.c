/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:31:14 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/15 15:19:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"
#include "utils.h"
#include "operations.h"

void	init(t_stack *stack, size_t size)
{
	stack->size = 0;
	if (!(stack->arr = malloc(sizeof(int) * size)))
		errndie("Error: Allocation failed");
}

void	push(t_stack *dest, int val)
{
	int i;

	i = dest->size;
	while (i > 0)
	{
		dest->arr[i] = dest->arr[i - 1];
		i--;
	}
	dest->arr[0] = val;
	dest->size++;
}

void	erase(t_stack *stack, size_t index)
{
	size_t i;

	if (stack->size == 0 || index >= stack->size)
		return ;
	i = index;
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->size--;
}

void	put_on_top_of_a(t_stack *a, t_stack *b, size_t index)
{
	size_t	i;

	i = 0;
	if (index < a->size - index)
		while (i++ < index)
			print_and_launch("ra", a, b);
	else
		while (i++ < a->size - index)
			print_and_launch("rra", a, b);
}

void	put_on_top_of_b(t_stack *a, t_stack *b, size_t index)
{
	size_t	i;

	i = 0;
	if (index < b->size - index)
		while (i++ < index)
			print_and_launch("rb", a, b);
	else
		while (i++ < b->size - index)
			print_and_launch("rrb", a, b);
}
