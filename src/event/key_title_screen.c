/*
** EPITECH PROJECT, 2018
** key title screen
** File description:
** c file
*/

#include "my_rpg.h"

void key_title_screen(p_game *g, sfEvent *event)
{
	if (event->key.code == sfKeyReturn) {
		reset_status(g);
		g->status = 1;
	}
}
