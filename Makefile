# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/30 15:24:05 by aroi              #+#    #+#              #
#    Updated: 2018/08/04 14:27:53 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

SRC		=	main.c \
			color1.c \
			color2.c \
			draw_fractals.c \
			draw_info_table.c \
			init_and_create.c \
			key_mouse_mapping.c \
			key_mapping_2.c \
			set_burning_ship.c \
			set_julia.c \
			set_mandelbrot.c

OBJ		=	main.o \
			color1.o \
			color2.o \
			draw_fractals.o \
			draw_info_table.o \
			init_and_create.o \
			key_mouse_mapping.o \
			key_mapping_2.o \
			set_burning_ship.o \
			set_julia.o \
			set_mandelbrot.o

%.o: %.c
	@$(CC) -c -o $@ $< -I libft
	@echo "\033[32m...Making some magic...\033[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32mCrafting \033[1mlibft.a\033[0m\033[32m...\033[0m"
	@make -C libft
	@$(CC) $(OBJ) -o $(NAME) -I /usr/local/include -L /usr/local/lib \
	-lmlx libft/libft.a -framework OpenGL -framework AppKit
	@echo "\033[1;32m$(NAME)\033[0m\033[32m is ready to use!\033[0m"

clean:
	@make -C libft clean
	@rm -rf $(OBJ)
	@echo "\033[31mRemoving object files...\033[0m"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\033[31mRemoved \033[1mlibft.a\033[0m\033[31m \
	and \033[1m$(NAME)\033[0m\033[31m files.\033[0m"

re: fclean all