# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:31:47 by ekeinan           #+#    #+#              #
#    Updated: 2025/01/08 11:58:45 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker_ekeinan
BONUS_NAME = .bonus

LIBFT_DIR = libft_full
LIBFT_LIB = $(LIBFT_DIR)/libft_full.a

SRC_CORE = main.c \
		   args_to_list.c \
		   args_dupe_check.c \
		   utils.c \
		   turks.c \
		   checks.c \
		   rotational_checks.c \
		   rotational_actions.c \
		   rotate.c \
		   swap.c \
		   push.c

SRC_BONUS = checker.c \
			args_to_list.c \
		  	args_dupe_check.c \
			utils.c \
			checks.c \
			rotate.c \
			swap.c \
			push.c

COMPILE_FLAGS = -Wall -Wextra -Werror

OBJ_CORE = $(SRC_CORE:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) -s --no-print-directory

%.o: %.c
	cc $(COMPILE_FLAGS) -c $< -o $@

$(NAME): $(LIBFT_LIB) $(OBJ_CORE)
	cc $(COMPILE_FLAGS) $(OBJ_CORE) $(LIBFT_LIB) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT_LIB) $(OBJ_BONUS)
	cc $(COMPILE_FLAGS) $(OBJ_BONUS) $(LIBFT_LIB) -o $(CHECKER_NAME)
	@touch $(BONUS_NAME)

clean:
	@make -C $(LIBFT_DIR) $@ --no-print-directory
	@rm -f $(OBJ_CORE) $(OBJ_BONUS)

fclean: clean
	@make -C $(LIBFT_DIR) $@ --no-print-directory
	rm -f $(NAME) $(CHECKER_NAME) $(BONUS_NAME) tags

re: fclean all

neat: $(NAME) clean
	ctags -R *
	clear

.PHONY: all bonus clean fclean re
