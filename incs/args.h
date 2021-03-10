#ifndef INIT_ARGS_H
#define INIT_ARGS_H

#include "stack.h"

#define O_VERBOSE 1
#define O_COLOR 2

void	check_argument_validity(size_t argc, char **argv, int allow_options);
void	set_values(t_stack *stack, size_t argc, char **argv, int allow_options);

#endif
