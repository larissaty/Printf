# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 16:22:36 by ltayra-y          #+#    #+#              #
#    Updated: 2024/11/19 19:43:48 by ltayra-y         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = ft_printf.c \
			print_ptr.c \
			print_str.c \
			print_nbr.c \
			print_hex.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

# CC Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
		@ar rcs $(NAME) $(OBJ_FILES)
		@ranlib $(NAME)
%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning Rules
clean:
		@rm -f $(OBJ_FILES)

fclean: clean
		@rm -f $(NAME)

re: fclean all

#Special Directives
.PHONY: all clean fclean re

