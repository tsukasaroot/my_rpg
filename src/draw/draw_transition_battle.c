/*
** EPITECH PROJECT, 2018
** draw transition battle
** File description:
** c file
*/

#include "my_rpg.h"

void draw_transition_battle(p_game *g)
{
	sfVector2f center = sfView_getCenter(g->view);
	int ct = 0;

	if (g->second_tx >= 0.05) {
		g->count_tx++;
		if (g->count_tx >= 18) {
			g->count_tx = 0;
			g->status = 3;
			fight_start(g, 1);
		}
		ct = g->count_tx;
		sfSprite_setTexture(g->sprite_tx, g->tb[ct], sfTrue);
		sfClock_restart(g->clock_tx);
	}
	center.x = center.x - 800;
	center.y = center.y - 450;
	sfSprite_setPosition(g->sprite_tx, center);
	sfRenderWindow_drawSprite(g->window, g->sprite_tx, NULL);
}
