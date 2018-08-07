# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/30 15:24:05 by aroi              #+#    #+#              #
#    Updated: 2018/08/07 10:47:54 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
OS			=	$(shell uname)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

ifeq ($(OS), Linux)
FLAGS_PLUS	=	-L ./minilibx -lmlx -lm -lXext -lX11
else
FLAGS_PLUS	=	-L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
endif

FILES		=	main \
				color1 \
				color2 \
				draw_fractals \
				draw_info_table \
				init_and_create \
				key_mouse_mapping \
				key_mapping_2 \
				set_burning_ship \
				set_julia \
				set_mandelbrot

INCLUDES	=	-I ./includes -I ./libft
SRC			=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ			=	$(addprefix obj/, $(addsuffix .o, $(FILES)))

all: $(NAME)

obj/%.o: src/%.c
	@$(CC) -o $@ -c $^ $(FLAGS) $(INCLUDES)
	@echo "\033[32m...Making some magic...\033[0m"

$(NAME): libft/libft.a mlx $(OBJ)
	@echo "\033[32mCrafting \033[1mlibft.a\033[0m\033[32m...\033[0m"
	@$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(FLAGS_PLUS) libft/libft.a
	@echo "\033[1;32m$(NAME)\033[0m\033[32m is ready to use!\033[0m"

libft/libft.a:
	@make -C libft

ifeq ($(OS), Linux)
mlx:
	@make -C minilibx
else
mlx:
	@make -C minilibx_macos
endif


clean: clean_mlx
	@make -C libft clean
	@rm -rf $(OBJ)
	@echo "\033[31mRemoving object files...\033[0m"

ifeq ($(OS), Linux)
clean_mlx:
	@make -C minilibx clean
else
clean_mlx:
	@make -C minilibx_macos clean
endif

fclean: clean_mlx
	@make -C libft fclean
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@echo "\033[31mRemoving object files...\033[0m"
	@echo "\033[31mRemoved \033[1m$(NAME)\033[0m\033[31m file.\033[0m"

re: fclean all

.PHONY: all clean
.NOTPARALLEL: all $(NAME) libft mlx clean clean_mlx fclean re
