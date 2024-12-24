# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:31:47 by ekeinan           #+#    #+#              #
#    Updated: 2024/12/21 18:47:27 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = libft_full
LIBFT_LIB = libft_full.a

SRC_CORE = utils.c \
		   checks.c \
		   args_to_list.c \
		   args_dupe_check.c \
		   main.c \
		   swap.c \
		   push.c \
		   rotate.c

COMPILE_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@cd $(LIBFT_DIR) && make --no-print-directory
	cc $(COMPILE_FLAGS) $(SRC_CORE) $(LIBFT_DIR)/$(LIBFT_LIB) -o $(NAME)

clean:
	@cd $(LIBFT_DIR) && make $@ --no-print-directory
	@rm -f $(BONUS_NAME)

fclean: clean
	@cd $(LIBFT_DIR) && make $@ --no-print-directory
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
