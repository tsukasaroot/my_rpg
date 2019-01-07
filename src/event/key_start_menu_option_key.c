/*
** EPITECH PROJECT, 2018
** key start menu option key
** File description:
** c file
*/

#include "my_rpg.h"

int key_start_menu_option_key_change(p_game *g, sfEvent *event)
{
	if (g->change_key == 0)
		return (0);
	if (event->key.code == sfKeyEscape)
		g->change_key = 0;
	if (is_key_free(g, event)) {
		key_start_menu_change_key(g, event);
		g->change_key = 0;
	}
	return (1);
}

void key_start_menu_option_key(p_game *g, sfEvent *event)
{
	if (key_start_menu_option_key_change(g, event) == 1)
		return;
	switch (event->key.code) {
		case sfKeyEscape:
			g->status_start_menu = 2;
			g->option_select = 1;
			break;
		case sfKeyUp:
			if (g->option_select > 1)
				g->option_select -= 1;
			break;
		case sfKeyDown:
			if (g->option_select < 5)
				g->option_select += 1;
			break;
		case sfKeyReturn:
			g->change_key = 1;
		default:
			break;
	}
}
