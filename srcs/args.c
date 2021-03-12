/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:00:32 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:07:00 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "utils.h"
#include <stdlib.h>

void		check_argument_validity(size_t argc, char **argv, int opts_on)
{
	size_t	i;
	int		atoi_success;

	i = 1;
	if (argc <= 1)
		errndie("Error: Not enough arguments.\n");
	while (i < argc)
	{
		if (opts_on && (!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-c")))
		{
			i++;
			continue;
		}
		ft_atoi(argv[i], &atoi_success);
		if (!atoi_success)
			errndie("Error: Argument is not a valid integer.\n");
		i++;
	}
}

static void	check_duplicated(t_stack *stack)
{
	size_t i;
	size_t j;

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

void		set_values(t_stack *stack, size_t argc, char **argv, int opts_on)
{
	size_t	i;
	int		success;

	i = 1;
	while (i < argc)
	{
		if (opts_on && (!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-c")))
		{
			i++;
			continue;
		}
		stack->arr[i - 1] = ft_atoi(argv[i], &success);
		stack->size++;
		if (!success)
			errndie("Error: Argument is not a valid integer.\n");
		i++;
	}
	check_duplicated(stack);
}
