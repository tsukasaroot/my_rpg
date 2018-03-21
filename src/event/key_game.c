/*
** EPITECH PROJECT, 2018
** key game
** File description:
** c file
*/

#include "my_rpg.h"

void key_player_move(p_game *g, sfEvent *event)
{
	if (g->player_move == 2)
		return;
	g->player_move = 1;
	switch (event->key.code) {
		case sfKeyDown:
			g->player_direction = 0;
			break;
		case sfKeyUp:
			g->player_direction = 1;
			break;
		case sfKeyLeft:
			g->player_direction = 2;
			break;
		case sfKeyRight:
			g->player_direction = 3;
			break;
		default:
			g->player_move = 0;
			break;
	}
}

void key_game(p_game *g, sfEvent *event)
{
	switch (event->key.code) {
		case sfKeyEscape:
			reset_status(g);
			g->status = 4;
			break;
		default:
			key_player_move(g, event);
			break;
	}
}
