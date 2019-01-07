/*
** EPITECH PROJECT, 2018
** update transition battle
** File description:
** c file
*/

#include "my_rpg.h"

void update_transition_battle(p_game *g)
{
	sfTime timex;

	timex = sfClock_getElapsedTime(g->clock_tx);
	g->second_tx = timex.microseconds / 1000000.0;
	draw_game(g);
	draw_transition_battle(g);
}
