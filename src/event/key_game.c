/*
** EPITECH PROJECT, 2018
** key game
** File description:
** c file
*/

#include "my_rpg.h"

void key_player_move_key_part2(p_game *g, sfEvent *event)
{
	if (event->key.code == g->key_move_right) {
		g->key_press_move_up = 0;
		g->key_press_move_down = 0;
		g->key_press_move_left = 0;
		g->key_press_move_right = 1;
	}
}

void key_player_move_key(p_game *g, sfEvent *event)
{
	if (event->key.code == g->key_move_down) {
		g->key_press_move_up = 0;
		g->key_press_move_down = 1;
		g->key_press_move_left = 0;
		g->key_press_move_right = 0;
	} else if (event->key.code == g->key_move_up) {
		g->key_press_move_up = 1;
		g->key_press_move_down = 0;
		g->key_press_move_left = 0;
		g->key_press_move_right = 0;
	} else if (event->key.code == g->key_move_left) {
		g->key_press_move_up = 0;
		g->key_press_move_down = 0;
		g->key_press_move_left = 1;
		g->key_press_move_right = 0;
	} else {
		key_player_move_key_part2(g, event);
	}
}

void key_game(p_game *g, sfEvent *event)
{
	if (g->player_move == 0 && event->key.code == sfKeyEscape) {
		reset_status(g);
		g->status = 4;
	} else if (g->player_move == 0 && event->key.code == g->key_inventory) {
		reset_status(g);
		g->status = 4;
		g->status_game_menu = 1;
	} else if (g->player_move == 0 && event->key.code == sfKeyReturn) {
		if (g->player_move == 0)
			player_interaction(g);
	} else
		key_player_move_key(g, event);
}
