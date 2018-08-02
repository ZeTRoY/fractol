# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/30 15:24:05 by aroi              #+#    #+#              #
#    Updated: 2018/08/01 20:26:15 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

SRC		=	main.c 

OBJ		=	main.o 

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