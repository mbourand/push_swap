/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:59:18 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:28:46 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

void	launch_operation(char *str, t_stack *a, t_stack *b, int options);
void	print_and_launch(char *str, t_stack *a, t_stack *b);

#endif
