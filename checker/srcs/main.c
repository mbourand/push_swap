/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:32:46 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/09 02:32:26 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "operations.h"
#include "gnl.h"

void	check_argument_validity(int argc, char **argv)
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

void	set_values(t_stack *stack, int argc, char **argv)
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

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		ret;
	char	*line;

	check_argument_validity(argc, argv);
	init(&a, argc - 1);
	init(&b, argc - 1);
	set_values(&a, argc, argv);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		launch_operation(line, &a, &b);
		free(line);
	}
	if (ret == -1)
		errndie("Error: Couldn't read stdin.\n");
	if (b.size == 0 && is_sorted(&a))
		ft_putstr("OK\n", 1);
	else
		ft_putstr("KO\n", 1);
	free(a.arr);
	free(b.arr);
	free(line);
	return (0);
}
