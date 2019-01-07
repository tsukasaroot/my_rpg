##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

CSFML	=	-l c_graph_prog

SRC	=	src/game_loop.c				\
		src/main.c				\
		src/reset_status.c			\
		src/basic/my_put_nbr.c			\
		src/basic/my_strcmp.c			\
		src/basic/get_next_line.c		\
		src/basic/basic.c			\
		src/basic/get_nbr.c			\
		src/basic/get_map.c			\
		src/basic/player_can_walk.c		\
		src/basic/check_player_case.c		\
		src/basic/player_interaction.c		\
		src/basic/flag.c			\
		src/basic/bad_argument.c		\
		src/basic/my_str_to_wordtab.c		\
		src/basic/change_item.c			\
		src/csfml/add_item.c			\
		src/csfml/set_img_sprite.c		\
		src/csfml/set_img_pos.c			\
		src/csfml/set_img_rect_pos.c		\
		src/csfml/set_img_rect_size.c		\
		src/csfml/set_img_relative_pos.c	\
		src/csfml/set_img_center.c		\
		src/csfml/set_text_pos.c		\
		src/csfml/draw_button.c			\
		src/csfml/check_button.c		\
		src/csfml/free_img.c			\
		src/csfml/draw_nbr.c			\
		src/csfml/fight_start.c			\
		src/csfml/draw_sprite.c			\
		src/csfml/set_volume.c			\
		src/csfml/is_key_free.c			\
		src/csfml/draw_text_key.c		\
		src/csfml/draw_text.c			\
		src/csfml/find_key.c			\
		src/init/game_init.c			\
		src/init/game_init2.c			\
		src/init/game_init3.c			\
		src/init/game_init4.c			\
		src/init/set_class.c			\
		src/init/create_title_screen.c		\
		src/init/create_transition_battle.c	\
		src/init/get_items.c			\
		src/draw/draw_get_player_name.c		\
		src/draw/draw_start_menu.c		\
		src/draw/draw_start_menu_option.c	\
		src/draw/draw_start_menu_key_option.c	\
		src/draw/draw_start_menu_load.c		\
		src/draw/draw_menu.c			\
		src/draw/draw_title_screen.c		\
		src/draw/draw_fight.c			\
		src/draw/draw_zone.c			\
		src/draw/draw_game.c			\
		src/draw/draw_map.c			\
		src/draw/draw_sub_menu.c		\
		src/draw/draw_sub_menu_2.c		\
		src/draw/draw_menu_item.c		\
		src/draw/draw_menu_equip.c		\
		src/draw/draw_transition_battle.c	\
		src/event/event.c			\
		src/event/event_click.c			\
		src/event/event_click_skills_menu.c	\
		src/event/key_title_screen.c		\
		src/event/key_start_menu.c		\
		src/event/key_start_menu_option.c	\
		src/event/key_start_menu_option_key.c	\
		src/event/key_start_menu_change_key.c	\
		src/event/key_get_player_name.c		\
		src/event/key_game.c			\
		src/event/key_menu.c			\
		src/event/button_start_menu.c		\
		src/event/button_game_menu.c		\
		src/update/update_intro.c		\
		src/update/update_game.c		\
		src/update/update_player.c		\
		src/update/update_player_animation.c	\
		src/update/update_title_screen.c	\
		src/update/update_transition_battle.c	\
		src/update/update_menu.c		\
		src/update/update_start_menu.c		\
		src/update/update_sub_menu_item.c	\
		src/update/update_sub_menu_2.c		\
		src/update/update_fight.c		\
		src/destroy/game_destroy.c		\
		src/dialogue_engine/dialogue.c		\
		src/dialogue_engine/parser.c		\
		src/get_objs/get_class_stats.c		\
		src/particules/particules.c		\

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
