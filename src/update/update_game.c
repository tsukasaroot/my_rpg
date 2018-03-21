/*
** EPITECH PROJECT, 2018
** update game
** File description:
** c file
*/

#include "my_rpg.h"

void update_game(p_game *g)
{
	update_player(g);
	sfView_setCenter(g->view, g->i_player.pos);
	sfRenderWindow_setView(g->window, g->view);
	draw_game(g);
}
