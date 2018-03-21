/*
** EPITECH PROJECT, 2018
** key menu
** File description:
** c file
*/

#include "my_rpg.h"

void key_menu(p_game *g, sfEvent *event)
{
	if (event->key.code == sfKeyEscape) {
		if (g->status_game_menu == 0) {
			reset_status(g);
			g->status = 2;
		} else
			g->status_game_menu = 0;
	}
}
