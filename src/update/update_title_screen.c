/*
** EPITECH PROJECT, 2018
** update_title_screen
** File description:
** c file
*/

#include "my_rpg.h"

void update_title_screen(p_game *g)
{
	sfTime timex;

	timex = sfClock_getElapsedTime(g->clock_tx);
	g->second_tx = timex.microseconds / 1000000.0;
	draw_title_screen(g);
}
