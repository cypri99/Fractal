# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 13:33:59 by cmartini          #+#    #+#              #
#    Updated: 2020/01/28 23:25:52 by cmartini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
GENERAL	= julia.c juliamx.c key.c main.c mandel.c menace.c save_image.c tricorn.c
SRC = $(addprefix src/, $(GENERAL))
OBJ = *.o
MINILIBX = minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
INC3 = -I inc/
FLAGS = -Wall -Wextra -Werror
LLIB = libft.a

reprog: fclean all

all: $(NAME)

$(NAME):
	@echo -n 'Compiling FRACTOL...'
	@cp libft/libft.a .
	gcc -o $(NAME) $(SRC) $(LLIB) $(MINILIBX) $(INC3)
	@echo "\t\x1b[92m✓✓\x1b[0m\n"

lib:
	@echo -n 'Compiling libft...'
	@make -C libft/ re
	@cp libft/libft.a .
	@echo "\t\t\x1b[92m✓\x1b[0m\n"

totall: lib all

clean:
	@rm -rf build

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LLIB)
	@echo "\t\n\x1b[96mFRACTOL \x1b[91mlibrary has been cleaned!\x1b[0m\n"

totfclean: fclean
	@make -C libft/ fclean
	@echo "\x1b[96mLibft has been cleaned.\x1b[0m\t\x1b[91mDon't forget to\
		recompile it...\n\x1b[0m"

re: totfclean totall

tot: totfclean totall