# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 14:14:11 by jochang           #+#    #+#              #
#    Updated: 2019/03/21 14:14:12 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = src/main.c \
	src/ft_setopt.c \
	src/sort_av.c \
	src/fix_path.c \
	src/ft_ls.c \
	src/get_list.c \
	src/save_one.c \
	src/sort_list.c \
	src/merge_sort.c \
	src/set_size.c \
	src/loop_iter.c \
	src/print_info.c \
	src/print_type.c \
	src/print_permissions.c \
	src/get_line_capacity.c \
	src/free_list.c \
	src/add_list.c \

INC = -I inc \
	-I libft/inc \

LFT = -L libft -lft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME):
	@make -C libft
	@echo "\033[32mmaking ft_ls...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(INC) $(LFT)

.PHONY: clean
clean:
	@make -C libft clean

.PHONY: fclean
fclean:
	@make -C libft fclean
	@echo "\033[33mremoving executable...\033[0m"
	@/bin/rm -f $(NAME)

.PHONY: re
re: fclean all