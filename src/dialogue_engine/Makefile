SRC	=	main_dialogue.c		\
		../basic/basic.c	\
		../basic/get_next_line.c\
		parser.c

OBJ	=	$(SRC:.c=.o)

NAME	=	test

CFLAGS	=	-Wall -Wextra -fno-builtin -g -Iinclude

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re
