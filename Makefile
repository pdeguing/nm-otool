# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 11:13:34 by pdeguing          #+#    #+#              #
#    Updated: 2019/01/04 08:31:12 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_NM		= ft_nm
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

LIBFT		= libft/libft.a
INCLUDES	= -I ./includes/ -I./libft/includes

SRCDIRNM	= srcs/
SRCSNM		= nm.c main.c symtab.c is_type.c

all: $(NAME_NM)

$(LIBFT):
	@cd libft/ && make

$(NAME_NM): $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME_NM) $(INCLUDES) $(LIBFT) $(addprefix $(SRCDIRNM), $(SRCSNM))

clean:
	@/bin/rm -f $(OBJSNM)
	@cd libft/ && make clean

fclean: clean
	@/bin/rm -f $(NAME_NM)
	@cd libft/ && make fclean

re: fclean all

.PHONY: clean fclean all re $(NAME_NM) $(NAME_OTOOL)
