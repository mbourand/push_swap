# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 15:50:28 by mbourand          #+#    #+#              #
#    Updated: 2020/09/09 14:53:30 by nforay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_NAME	= push_swap
CHECKER_NAME	= checker

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC_PATH= srcs/
OBJ_PATH= objs/

SRC_NAME		= args.c gnl.c gnlutils.c operations.c stack.c utils.c
PUSH_SWAP_MAIN	= push_swap.c
CHECKER_MAIN	= checker.c

OBJ_NAME= $(SRC_NAME:.c=.o)

INC= -Iincs/
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
PUSH_SWAP_MAIN_OBJ = $(addprefix $(OBJ_PATH), $(PUSH_SWAP_MAIN:.c=.o))
CHECKER_MAIN_OBJ = $(addprefix $(OBJ_PATH), $(CHECKER_MAIN:.c=.o))
DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m
YEL= \033[33;1m

ifeq ($(DB),1)
	CFLAGS	+= -fsanitize=address -g3
endif

.PHONY: all re clean fclean

all: $(PUSH_SWAP_NAME) $(CHECKER_NAME)

$(PUSH_SWAP_NAME): $(OBJ) $(PUSH_SWAP_MAIN_OBJ)
	@echo "$(RED)[push_swap] : $(DEF)Compiling..."
	@$(CC) $(CFLAGS) -o $(PUSH_SWAP_NAME) $(OBJ) $(PUSH_SWAP_MAIN_OBJ) $(INC)
	@echo "$(RED)[push_swap] : $(DEF)Compilation $(GRN)[OK]$(DEF)"

$(CHECKER_NAME): $(OBJ) $(CHECKER_MAIN_OBJ)
	@echo "$(RED)[push_swap] : $(DEF)Compiling..."
	@$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(OBJ) $(CHECKER_MAIN_OBJ) $(INC)
	@echo "$(RED)[push_swap] : $(DEF)Compilation $(GRN)[OK]$(DEF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[push_swap] :$(DEF) Compiling $@"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[push_swap] : $(DEF)Cleaning $(GRN)[OK]$(DEF)"

fclean: clean
	@rm -rf $(PUSH_SWAP_MAIN) $(CHECKER_NAME)
	@echo "$(RED)[push_swap] : $(DEF)Full Cleaning $(GRN)[OK]$(DEF)"

re: fclean all
