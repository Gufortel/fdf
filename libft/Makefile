# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 00:01:50 by gufortel          #+#    #+#              #
#    Updated: 2019/07/20 23:04:53 by gufortel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c\
	  ft_bzero.c\
	  ft_realloc.c\
	  nmatch.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_itoa.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putwchar.c\
	  ft_putwstr.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strjoinfree.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strstri.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_sqrt.c\
	  arg2.c\
	  argbi.c\
	  argc.c\
	  argdate.c\
	  argdi.c\
	  argerrno.c\
	  argerrno2.c\
	  argl.c\
	  argnb.c\
	  argo.c\
	  argonorm.c\
	  argss.c\
	  color.c\
	  conv.c\
	  convnorme.c\
	  dev.c\
	  ft_erreur.c\
	  ft_list_var.c\
	  ft_printf.c\
	  ft_printfnorm.c\
	  index.c\
	  parse.c\
	  parsenorm.c\
	  treat.c\
	  unprint.c\
	  vft_printf.c\
	  vft_printfnorm.c\
	  ft_itoa_base.c\
	  ft_itoa_base_neg.c\
	  ft_len_wchar_to_char.c\
	  ft_val_wchar.c\
	  ft_strupper.c\
	  get_next_line.c\
	  match.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(SRC) $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	
all: $(NAME)

clean:
	@rm -Rf $(OBJ)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all

.PHONY: clean fclean all re 
