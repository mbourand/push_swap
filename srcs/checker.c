/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:32:46 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/10 15:31:58 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "operations.h"
#include "gnl.h"
#include "args.h"
#include <stdio.h>

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
