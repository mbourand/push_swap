#include <stdlib.h>
#include "stack.h"
#include "utils.h"

void	init(t_stack* stack, size_t size)
{
	stack->size = 0;
	if (!(stack->arr = malloc(sizeof(int) * size)))
		errndie("Error: Allocation failed");
}

void	push(t_stack *dest, int val)
{
	int i;

	i = dest->size - 1;
	while (i >= 0)
	{
		dest->arr[i] = dest->arr[i + 1];
		i--;
	}
	dest->arr[0] = val;
	dest->size++;
}

void	pop(t_stack *stack)
{
	size_t i;

	i = 0;
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
			return FALSE;
		i++;
	}
	return TRUE;
}
