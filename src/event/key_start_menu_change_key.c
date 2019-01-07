/*
** EPITECH PROJECT, 2018
** key start menu change key
** File description:
** c file
*/

#include "my_rpg.h"

void key_start_menu_change_key(p_game *g, sfEvent *event)
{
	switch (g->option_select) {
		case 1:
			g->key_move_up = event->key.code;
			break;
		case 2:
			g->key_move_down = event->key.code;
			break;
		case 3:
			g->key_move_left = event->key.code;
			break;
		case 4:
			g->key_move_right = event->key.code;
			break;
		case 5:
			g->key_inventory = event->key.code;
			break;
	}
}
