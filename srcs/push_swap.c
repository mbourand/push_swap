/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:10:50 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:41:52 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "args.h"
#include "stack.h"
#include "sort.h"

int			main(int argc, char **argv)
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
