# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelhom <adelhom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 16:56:16 by adelhom           #+#    #+#              #
#    Updated: 2016/12/03 15:52:48 by adelhom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

SRC =	$(SRC_STRING)	\
		$(SRC_PRINT)	\
		$(SRC_MATH)		\
		$(SRC_LIST)		\
		$(SRC_POINT)	\
		$(SRC_MEMORY)	\


SRC_STRING =ft_strcmp.c		\
			ft_strncmp.c	\
			ft_strlen.c		\
			ft_strdup.c		\
			ft_strcpy.c		\
			ft_strncpy.c	\
			ft_strcat.c		\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_isalpha.c	\
			ft_isupper.c	\
			ft_islower.c	\
			ft_ishexdigit.c \
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_strsplit.c	\
			ft_splitcount.c \
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_itoa.c		\
			ft_atoi.c		\

SRC_PRINT =	ft_putchar.c	\
			ft_putchar_fd.c	\
			ft_putstr.c		\
			ft_putstr_fd.c	\
			ft_putendl.c	\
			ft_putendl_fd.c	\
			ft_putnbr.c		\
			ft_putnbr_fd.c	\

SRC_MATH =	ft_sqrtint.c	\
			ft_powerint.c	\

SRC_LIST =	ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstpushback.c\
			ft_lstiter.c	\
			ft_lstmap.c		\
			ft_lstfree.c	\
			ft_lstsize.c	\
			ft_lstrev.c		\

SRC_POINT = ft_pointnew.c   \

SRC_MEMORY =ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memalloc.c	\
			ft_memdel.c		\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.PHONY: clean fclean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
