#include <stdlib.h>
#include "stack.h"
#include "utils.h"

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

void	init(t_stack* stack, size_t size)
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
		return;
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

size_t		find_biggest(t_stack *stack)
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
