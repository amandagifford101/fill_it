# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agifford <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 21:13:41 by agifford          #+#    #+#              #
#    Updated: 2018/05/29 21:27:00 by agifford         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = backtrack3.c \
	  debugg.c \
	  deletions.c \
	  list_stuff.c \
	  main.c \
	  structs.c \
	  validation.c

LIBFT = libft

GCC = gcc -Wall -Wextra -Werror

$(NAME) : all

all :
	@make -C $(LIBFT)
	$(GCC) $(SRC) $(LIBFT)/libft.a -o $(NAME)

clean :
	@make -C $(LIBFT) clean

fclean : clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)

re : fclean all
