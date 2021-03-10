/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:32:46 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/10 19:04:32 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "operations.h"
#include "gnl.h"
#include "args.h"
#include <stdio.h>

static void	set_options(size_t argc, char **argv, int *options)
{
	size_t	i;

	i = 1;
	*options = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			*options |= O_VERBOSE;
		else if (ft_strcmp(argv[i], "-c") == 0)
			*options |= O_COLOR;
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		ret;
	char	*line;
	int		options;

	check_argument_validity(argc, argv, TRUE);
	set_options(argc, argv, &options);
	init(&a, argc - 1);
	init(&b, argc - 1);
	set_values(&a, argc, argv, TRUE);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		launch_operation(line, &a, &b, options);
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
