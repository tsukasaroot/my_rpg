##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

CSFML	=	-l c_graph_prog

SRC	=	src/bad_argument.c			\
		src/flag.c				\
		src/game_loop.c				\
		src/main.c				\
		src/get_map.c				\
		src/reset_status.c			\
		src/player_can_walk.c			\
		src/basic/my_put_nbr.c			\
		src/basic/my_strcmp.c			\
		src/basic/get_next_line.c		\
		src/basic/basic.c			\
		src/basic/get_nbr.c			\
		src/csfml/set_img_sprite.c		\
		src/csfml/set_img_pos.c			\
		src/csfml/set_img_rect_pos.c		\
		src/csfml/set_img_rect_size.c		\
		src/csfml/set_img_relative_pos.c	\
		src/csfml/set_img_center.c		\
		src/csfml/draw_button.c			\
		src/csfml/check_button.c		\
		src/csfml/free_img.c			\
		src/csfml/draw_nbr.c			\
		src/csfml/create_title_screen.c		\
		src/init/game_init.c			\
		src/draw/draw_start_menu.c		\
		src/draw/draw_start_menu_option.c	\
		src/draw/draw_menu.c			\
		src/event/event.c			\
		src/event/key_title_screen.c		\
		src/event/key_game.c			\
		src/event/key_menu.c			\
		src/event/button_start_menu.c		\
		src/event/button_game_menu.c		\
		src/draw/draw_game.c			\
		src/draw/draw_map.c			\
		src/draw/draw_sub_menu.c		\
		src/draw/draw_sub_menu_2.c		\
		src/update/update_game.c		\
		src/update/update_player.c		\
		src/update/update_title_screen.c	\
		src/update/update_menu.c		\
		src/update/update_start_menu.c		\
		src/update/update_sub_menu_item.c	\
		src/update/update_sub_menu_2.c		\
		src/destroy/game_destroy.c		\
		src/draw/draw_title_screen.c

NAME	=	my_rpg

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -fno-builtin -g -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(CSFML)

.SILENT: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(CSFML)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
