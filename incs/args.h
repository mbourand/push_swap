/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:00:03 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:00:10 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "stack.h"

# define O_VERBOSE 1
# define O_COLOR 2

void	check_argument_validity(size_t argc, char **argv, int allow_options);
void	set_values(t_stack *stack, size_t argc, char **argv, int allow_options);

#endif
