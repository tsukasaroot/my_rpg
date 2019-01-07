/*
** EPITECH PROJECT, 2018
** draw title screen
** File description:
** c file
*/

#include "my_rpg.h"

void draw_title_screen(p_game *g)
{
	sfVector2f pos;
	int ct = 0;

	if (g->second_tx >= 0.05) {
		g->count_tx++;
		if (g->count_tx == 40)
			g->count_tx = 0;
		ct = g->count_tx;
		sfSprite_setTexture(g->sprite_tx, g->title_scr[ct], sfTrue);
		sfClock_restart(g->clock_tx);
	}
	pos.x = 800;
	pos.y = 450;
	sfView_setCenter(g->view, pos);
	sfRenderWindow_setView(g->window, g->view);
	sfRenderWindow_drawSprite(g->window, g->sprite_tx, NULL);
}
