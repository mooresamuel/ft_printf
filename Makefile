# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samoore <samoore@student.42london.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 16:27:09 by samoore           #+#    #+#              #
#    Updated: 2023/11/29 20:44:26 by samoore          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = ft_integers.c \
			ft_printf.c \
			ft_put.c \
			ft_flags.c \
			ft_len.c \
			ft_process.c \
			ft_string_and_hex.c \
			ft_print_common.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
NAME = libftprintf.a

all: $(NAME)

bonus: $(NAME)

$(NAME) : $(OBJ_FILES)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
