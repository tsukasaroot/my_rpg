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

	if (g->second_tx >= 0.05) {
		g->count_tx++;
		if (g->count_tx == 80)
			g->count_tx = 0;
		sfSprite_setTexture(g->sprite_tx, g->title_scr[g->count_tx], sfTrue);
		sfClock_restart(g->clock_tx);
	}
	pos.x = 800;
	pos.y = 450;
	sfView_setCenter(g->view, pos);
	sfRenderWindow_setView(g->window, g->view);
	sfRenderWindow_drawSprite(g->window, g->sprite_tx, NULL);
}
