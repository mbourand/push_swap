/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:31:14 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:32:15 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

int		get_nb_to_top(t_stack *a, size_t index)
{
	return (ft_min(index, a->size - index));
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
