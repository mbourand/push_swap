/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:56:24 by user42            #+#    #+#             */
/*   Updated: 2021/03/15 15:08:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

size_t	find_biggest(t_stack *stack)
{
	size_t	i;
	size_t	max;

	i = 1;
	max = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] > stack->arr[max])
			max = i;
		i++;
	}
	return (max);
}

size_t	find_nth_smallest_index(t_stack *stack, size_t n)
{
	t_stack	cpy;
	size_t	i;
	size_t	min;

	i = 0;
	cpy.size = stack->size;
	if (!(cpy.arr = malloc(sizeof(int) * stack->size)))
		errndie("Error: Allocation failed.\n");
	while (i < stack->size)
	{
		cpy.arr[i] = stack->arr[i];
		i++;
	}
	while (n-- > 0)
	{
		min = 0;
		i = 0;
		while (++i < cpy.size)
			if (cpy.arr[i] < cpy.arr[min])
				min = i;
		if (n == 0)
			return (freenret(cpy.arr, min));
		erase(&cpy, min);
	}
	return (-1);
}

int		find_nth_smallest(t_stack *stack, size_t n)
{
	t_stack	cpy;
	size_t	i;
	size_t	min;

	i = 0;
	cpy.size = stack->size;
	if (!(cpy.arr = malloc(sizeof(int) * stack->size)))
		errndie("Error: Allocation failed.\n");
	while (i < stack->size)
	{
		cpy.arr[i] = stack->arr[i];
		i++;
	}
	while (n-- > 0)
	{
		min = 0;
		i = 0;
		while (++i < cpy.size)
			if (cpy.arr[i] < cpy.arr[min])
				min = i;
		if (n == 0)
			return (freenret(cpy.arr, cpy.arr[min]));
		erase(&cpy, min);
	}
	return (0);
}

size_t	find_first_in_chunk(t_stack *stack, t_chunk *chunk)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] >= chunk->min && stack->arr[i] <= chunk->max)
			return (i);
		i++;
	}
	return (-1);
}

size_t	find_last_in_chunk(t_stack *stack, t_chunk *chunk)
{
	int	i;

	i = stack->size - 1;
	while (i >= 0)
	{
		if (stack->arr[i] >= chunk->min && stack->arr[i] <= chunk->max)
			return (i);
		i--;
	}
	return (-1);
}
