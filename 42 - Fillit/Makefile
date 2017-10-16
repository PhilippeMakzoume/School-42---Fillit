# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelhom <adelhom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 16:21:29 by adelhom           #+#    #+#              #
#    Updated: 2016/12/07 18:43:37 by pmakhzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ********************************* GENERAL ********************************** #
# **************************************************************************** #
NAME			= fillit

CC				= gcc
CFLAGS		= -Wall -Wextra -Werror
# ********************************** PATHS *********************************** #
# **************************************************************************** #
# ** Unused  ** #
OBJ_PATH = ./libft

SRC_NAME	= main.c	\
		  			input.c	\
		  			piece.c	\
		  			map.c
SRC_PATH = ./src

INC_PATH = ./includes
INC_NAME = fillit.h

LIB_PATH = ./libft
LIB_NAME = libft.a
# ********************************** ACCESS ********************************** #
# **************************************************************************** #
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))
LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))
# ********************************** RULES *********************************** #
# **************************************************************************** #
.PHONY : all clean fclean re
all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(SRC) $(LIB) -I $(INC) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIB_PATH)

fclean: clean
	$(MAKE) fclean -C $(LIB_PATH)
	rm -f $(NAME)

re: fclean all
