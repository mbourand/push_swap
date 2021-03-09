#include "utils.h"
#include "args.h"
#include "stack.h"
#include "operations.h"
#include <limits.h>

static void print_and_launch(char *str, t_stack *a, t_stack *b)
{
	ft_putstr(str, 1);
	ft_putstr("\n", 1);
	launch_operation(str, a, b);
}

static void sort(t_stack *a, t_stack *b)
{
	size_t max_index;
	long long max;
	size_t i;
	size_t found;

	found = 0;
	while (found < a->size)
	{
		max = (long long)INT_MIN - 1;
		max_index = 0;
		i = 0;
		while (i < a->size - found)
		{
			if (a->arr[i] > max)
			{
				max = a->arr[i];
				max_index = i;
			}
			i++;
		}
		i = 0;
		while (i++ < max_index)
			print_and_launch("pb", a, b);
		print_and_launch("ra", a, b);
		i = 0;
		while (i++ < max_index)
			print_and_launch("pa", a, b);
		found++;
	}
	i = 0;
	while (a->size)
		print_and_launch("pb", a, b);
	while (b->size)
	{
		print_and_launch("rrb", a, b);
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
