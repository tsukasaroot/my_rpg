/*
** EPITECH PROJECT, 2018
** update intro
** File description:
** c file
*/

#include "my_rpg.h"

void update_intro(p_game *g)
{
	if (g->status_intro == 1)
		draw_get_player_name(g);
	if (g->status_intro == 2) {
		g->status_intro = 3;
		g->status = 7;
	}
	if (g->status_intro == 3 && g->status == 6) {
		g->status_intro = 1;
		g->status = 2;
	}
}
