#ifndef STACK_H
#define STACK_H

typedef struct	s_stack
{
	int*	arr;
	size_t	size;
}				t_stack;

void	push(t_stack *dest, int i);
void	pop(t_stack *stack);
void	init(t_stack* stack, size_t size);
int		is_sorted(t_stack *stack);

#endif
