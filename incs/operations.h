/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:59:18 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:40:05 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

void	launch_operation(char *str, t_stack *a, t_stack *b, int options);
void	print_and_launch(char *str, t_stack *a, t_stack *b);
int		reverse_rotate_operation(t_stack *stack);
int		rotate_operation(t_stack *stack);
int		push_operation(t_stack *src, t_stack *dest);
int		swap_operation(t_stack *stack);

#endif
