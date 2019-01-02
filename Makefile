NAME_NM		= ft_nm
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I ./includes -I ./libft/includes
SRCS		:= $(addprefix $(SRCDIR)/, $(ALL))

SRCDIRNM	= srcs/
SRCSNM		= nm.c
OBJSNM		= $(addprefix $(SRCDIRNM), $(SRCSNM:.c=.o))

all: $(NAME_NM)

$(NAME_NM): $(OBJSNM)
		@$(CC) $(CFLAGS) -o $(NAME_NM) $(INCLUDES) $(OBJSNM)

clean:
		@/bin/rm -f $(OBJSNM)

fclean: clean
		@/bin/rm -f $(NAME_NM)

re: fclean all

.PHONY: clean fclean all re $(NAME_NM) $(NAME_OTOOL)
