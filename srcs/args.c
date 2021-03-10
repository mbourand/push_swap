#include "args.h"
#include "utils.h"
#include <stdlib.h>

void	check_argument_validity(size_t argc, char **argv)
{
	size_t	i;
	int		atoi_success;

	i = 1;
	if (argc <= 1)
		errndie("Error: Not enough arguments.\n");
	while (i < argc)
	{
		ft_atoi(argv[i], &atoi_success);
		if (!atoi_success)
			errndie("Error: Argument is not a valid integer.\n");
		i++;
	}
}

void	set_values(t_stack *stack, size_t argc, char **argv)
{
	size_t	i;
	size_t	j;
	int		success;

	i = 1;
	while (i < argc)
	{
		stack->arr[i - 1] = ft_atoi(argv[i], &success);
		stack->size++;
		if (!success)
			errndie("Error: Argument is not a valid integer.\n");
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (j != i && stack->arr[i] == stack->arr[j])
				errndie("Error: Duplicated arguments.\n");
			j++;
		}
		i++;
	}
}
