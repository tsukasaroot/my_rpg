/*
** EPITECH PROJECT, 2018
** is key free
** File description:
** c file
*/

#include "my_rpg.h"

int is_key_free_check_spe_key(sfEvent *event)
{
	switch (event->key.code) {
		case sfKeySpace:
		case sfKeyLeft:
		case sfKeyRight:
		case sfKeyUp:
		case sfKeyDown:
			return (1);
			break;
		default:
			break;
	}
	return (0);
}

int is_key_free_check_key(sfEvent *event)
{
	if (event->key.code < 27)
		return (1);
	else
		return (is_key_free_check_spe_key(event));
}

int is_key_used(p_game *g, sfEvent *event)
{
	if (event->key.code == g->key_move_up
	|| event->key.code == g->key_move_down
	|| event->key.code == g->key_move_left
	|| event->key.code == g->key_move_right
	|| event->key.code == g->key_inventory)
		return (1);
	return (0);
}

int is_key_free(p_game *g, sfEvent *event)
{
	if (is_key_free_check_key(event) == 1)
		if (is_key_used(g, event) == 0)
			return (1);
	return (0);
}
