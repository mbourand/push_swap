#include "utils.h"
#include "stack.h"

static int	swap_operation(t_stack *stack)
{
	int tmp;

	if (stack->size < 2)
		return TRUE;
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
	return TRUE;
}

static int	push_operation(t_stack *src, t_stack *dest)
{
	if (src->size == 0)
		return TRUE;
	push(dest, src->arr[0]);
	erase(src, 0);
	return TRUE;
}

static int rotate_operation(t_stack* stack)
{
	size_t i;
	int tmp;

	if (stack->size < 2)
		return TRUE;
	tmp = stack->arr[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->size - 1] = tmp;
	return TRUE;
}

static int reverse_rotate_operation(t_stack* stack)
{
	int i;
	int tmp;

	if (stack->size < 2)
		return TRUE;
	tmp = stack->arr[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
	return TRUE;
}

void	launch_operation(char *str, t_stack *a, t_stack *b)
{
	int ok = FALSE;

	if (!str)
		return;
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "ss") == 0)
		ok = swap_operation(a);
	if (ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0)
		ok = swap_operation(b);
	if (ft_strcmp(str, "pa") == 0)
		ok = push_operation(b, a);
	if (ft_strcmp(str, "pb") == 0)
		ok = push_operation(a, b);
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rr") == 0)
		ok = rotate_operation(a);
	if (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0)
		ok = rotate_operation(b);
	if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0)
		ok = reverse_rotate_operation(a);
	if (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0)
		ok = reverse_rotate_operation(b);
	if (!ok)
		errndie("Error: Unrecognized operation.\n");
}
