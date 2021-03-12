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
	launch_operation(str, a, b, 0);
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

static void three_sort(t_stack *a, t_stack *b)
{
	if (a->size != 3 || is_sorted(a))
		return;
	if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2] && a->arr[2] > a->arr[0])
		print_and_launch("sa", a, b);
	else if (a->arr[0] > a->arr[1] && a->arr[1] > a->arr[2] && a->arr[2] < a->arr[0])
	{
		print_and_launch("sa", a, b);
		print_and_launch("rra", a, b);
	}
	else if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2] && a->arr[2] < a->arr[0])
		print_and_launch("ra", a, b);
	else if (a->arr[0] < a->arr[1] && a->arr[1] > a->arr[2] && a->arr[2] > a->arr[0])
	{
		print_and_launch("sa", a, b);
		print_and_launch("ra", a, b);
	}
	else if (a->arr[0] < a->arr[1] && a->arr[1] > a->arr[2] && a->arr[2] < a->arr[0])
		print_and_launch("rra", a, b);
}

static void big_sort(t_stack *a, t_stack *b)
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

static void small_sort(t_stack *a, t_stack *b)
{
	size_t	cnt;

	if (is_sorted(a))
		return;
	while (a->size != 3)
		print_and_launch("pb", a, b);
	three_sort(a, b);
	while (b->size)
	{
		cnt = 0;
		while (b->arr[0] > find_nth_smallest(a, cnt + 1) && cnt < a->size)
			cnt++;
		put_on_top_of_a(a, b, cnt);
		print_and_launch("pa", a, b);
		put_on_top_of_a(a, b, find_nth_smallest_index(a, 1));
	}

}

static void sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (!is_sorted(a))
			print_and_launch("sa", a, b);
	}
	else if (a->size == 3)
		three_sort(a, b);
	else if (a->size < 6)
		small_sort(a, b);
	else
		big_sort(a, b);
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;

	check_argument_validity(argc, argv, FALSE);
	init(&a, argc - 1);
	init(&b, argc - 1);
	set_values(&a, argc, argv, FALSE);
	sort(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}
