/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:32:48 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:38:40 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "utils.h"
#include "args.h"

void			launch_operation(char *str, t_stack *a, t_stack *b, int options)
{
	int	ok;

	ok = FALSE;
	if (!str)
		return ;
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "ss") == 0)
		ok = swap_operation(a);
	if (ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0)
		ok = swap_operation(b);
	if (ft_strcmp(str, "pa") == 0)
		ok = push_operation(b, a);
	if (ft_strcmp(str, "pb") == 0)
		ok = push_operation(a, b);
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rr") == 0)
		ok = rotate_operation(a);
	if (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0)
		ok = rotate_operation(b);
	if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0)
		ok = reverse_rotate_operation(a);
	if (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0)
		ok = reverse_rotate_operation(b);
	if (!ok)
		errndie("Error: Unrecognized operation.\n");
	if (options & O_VERBOSE)
		print_stacks(a, b);
}

void			print_and_launch(char *str, t_stack *a, t_stack *b)
{
	ft_putstr(str, 1);
	ft_putstr("\n", 1);
	launch_operation(str, a, b, 0);
}
