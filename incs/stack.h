#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct	s_stack
{
	int*	arr;
	size_t	size;
}				t_stack;

typedef struct	s_chunk
{
	int		min;
	int		max;
}				t_chunk;

void	push(t_stack *dest, int i);
void	erase(t_stack *stack, size_t index);
void	init(t_stack* stack, size_t size);
int		is_sorted(t_stack *stack);
int		find_nth_smallest(t_stack *stack, size_t n);
size_t	find_nth_smallest_index(t_stack *stack, size_t n);
size_t	find_first_in_chunk(t_stack *stack, t_chunk *chunk);
size_t	find_last_in_chunk(t_stack *stack, t_chunk *chunk);
size_t	find_biggest(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b);

#endif
