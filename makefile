# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makacem <makacem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 09:47:22 by makacem           #+#    #+#              #
#    Updated: 2022/06/26 21:21:37 by makacem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

FLAGS = -Wall -Werror -Wextra

HEADER = so_long.h

SRC = src/so_long.c src/map_checker_utils.c src/map_checker.c src/so_long_utils.c src/key_hooks.c src/put_map.c \
		src/put_map_utils.c src/key_hooks_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a

GNL = gnl/get_next_line.c

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft/libft.a gnl/get_next_line.c \
	gnl/get_next_line_utils.c

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -c  $< -o $@

clean :
	@rm -f $(OBJ)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re : fclean all