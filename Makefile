# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:31:47 by ekeinan           #+#    #+#              #
#    Updated: 2025/01/01 17:07:51 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker_ekeinan
BONUS_NAME = .bonus

LIBFT_DIR = libft_full
LIBFT_LIB = libft_full.a

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

all: $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) -s --no-print-directory

$(NAME): $(LIBFT_LIB)
	cc $(COMPILE_FLAGS) $(SRC_CORE) $(LIBFT_DIR)/$(LIBFT_LIB) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT_LIB)
	cc $(COMPILE_FLAGS) $(SRC_BONUS) $(LIBFT_DIR)/$(LIBFT_LIB) -o $(CHECKER_NAME)
	@touch $(BONUS_NAME)

clean:
	@cd $(LIBFT_DIR) && make $@ --no-print-directory
	@rm -f $(CHECKER_NAME) $(BONUS_NAME)

fclean: clean
	@cd $(LIBFT_DIR) && make $@ --no-print-directory
	rm -f $(NAME)

re: fclean all

.PHONY: bonus .bonus all clean fclean re
