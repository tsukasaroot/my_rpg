/*
** EPITECH PROJECT, 2018
** update player animation
** File description:
** c file
*/

#include "my_rpg.h"

void update_player_animation(p_game *g)
{
	int i = sfTime_asMilliseconds(sfClock_getElapsedTime(g->playera_clock));

	if (g->player_move != 2)
		return;
	if (i > 200) {
		if (g->i_player.rect.top >= g->i_player.rect.height * 3)
			g->i_player.rect.top = 0;
		else {
			g->i_player.rect.top += g->i_player.rect.height;
			sfClock_restart(g->playera_clock);
		}
	}

}
