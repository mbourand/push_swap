#ifndef INIT_ARGS_H
#define INIT_ARGS_H

#include "stack.h"

void	check_argument_validity(size_t argc, char **argv);
void	set_values(t_stack *stack, size_t argc, char **argv);

#endif
