# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 17:14:20 by gufortel          #+#    #+#              #
#    Updated: 2019/07/20 23:16:15 by gufortel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAG = -Wall -Wextra -Werror

SRC = create_matrix.c\
	draw_line.c\
	fdf.c\
	image.c\
	main.c\
	parse.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

source:
	@make -C ./libft/
	@make -C ./minilibx_macos/

$(NAME): source $(OBJ) $(SRC)
	@gcc -c $(FLAG) $(SRC) 
	@gcc -o $(NAME) $(OBJ) $(FLAG) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit  ./libft/libft.a

clean:
	@make -C ./libft/ clean
	@make -C ./minilibx_macos/ clean
	@rm -Rf $(OBJ)

fclean: clean
	@make -C ./libft/ fclean
	@make -C ./minilibx_macos/ clean
	@rm -Rf $(NAME)

re:	fclean all
