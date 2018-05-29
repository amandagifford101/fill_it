NAME = libft.a

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	SHELL = /bin/zsh
else
	SHELL = /bin/bash
endif

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_bzero.c \
		ft_itoa.c \
		ft_mem{alloc,ccpy,chr,cmp,cpy,del,move,set}.c \
		ft_put{char,char_fd,endl,endl_fd,nbr,nbr_fd,str,str_fd}.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_str{iter,iteri}.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_str{map,mapi}.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_to{lower,upper}.c \
		ft_is{alnum,alpha,ascii,digit,print,upper,lower,word}.c \
		ft_int_len.c \
		ft_strsplit.c \
		ft_lst{add,del,delone,iter,map,new}.c \
		ft_atoi.c \
		ft_word_count.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $? $(SRC)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo "\033[37mlibrary built, Panda\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[37mobj files have been cleaned, Panda\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[37mcompiled files have been cleaned, Panda\033[0m"

re: fclean all

.PHONY: all clean fclean re

