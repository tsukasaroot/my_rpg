/*
** EPITECH PROJECT, 2018
** key start menu
** File description:
** c file
*/

#include "my_rpg.h"

void key_start_menu_load(p_game *g, sfEvent *event)
{
	switch (event->key.code) {
		case sfKeyEscape:
			g->status_start_menu = 0;
			break;
		default:
			break;
	}
}

void key_start_menu(p_game *g, sfEvent *event)
{
	if (g->status_start_menu == 1)
		key_start_menu_load(g, event);
	else if (g->status_start_menu == 2)
		key_start_menu_option(g, event);
	else if (g->status_start_menu == 3)
		key_start_menu_option_key(g, event);
}
