#include "utils.h"
#include "args.h"
#include "stack.h"
#include "operations.h"
#include <limits.h>
#include <stdio.h>

static void print_and_launch(char *str, t_stack *a, t_stack *b)
{
	ft_putstr(str, 1);
	ft_putstr("\n", 1);
	launch_operation(str, a, b);
}

static int get_nb_to_top(t_stack *a, size_t index)
{
	return ft_min(index, a->size - index);
}

static void put_on_top_of_a(t_stack *a, t_stack *b, size_t index)
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

static void put_on_top_of_b(t_stack *a, t_stack *b, size_t index)
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

static void sort(t_stack *a, t_stack *b)
{
	int		size_left;
	t_chunk	chunk;
	int		chunk_size = ft_sqrt(a->size) * 1.5f;
	int		first;
	int		last;
	int		todo;

	if (is_sorted(a))
		return;
	size_left = a->size;
	while (size_left > 0)
	{
		chunk.min = find_nth_smallest(a, a->size - size_left + 1);
		chunk.max = find_nth_smallest(a, ft_min(a->size, a->size - size_left + chunk_size));
		while (a->size)
		{
			first = find_first_in_chunk(a, &chunk);
			last = find_last_in_chunk(a, &chunk);
			if (first == -1 || last == -1)
				break;
			todo = (get_nb_to_top(a, first) < get_nb_to_top(a, last) ? first : last);
			put_on_top_of_a(a, b, todo);
			print_and_launch("pb", a, b);
		}
		size_left -= chunk_size;
	}
	while (b->size)
	{
		put_on_top_of_b(a, b, find_biggest(b));
		print_and_launch("pa", a, b);
	}
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;
	int		ret;
	char	*line;

	check_argument_validity(argc, argv);
	init(&a, argc - 1);
	init(&b, argc - 1);
	set_values(&a, argc, argv);
	sort(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}
