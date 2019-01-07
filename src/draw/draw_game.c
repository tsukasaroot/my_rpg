/*
** EPITECH PROJECT, 2018
** draw_game
** File description:
** c file
*/

#include "my_rpg.h"

void draw_zone_name(p_game *g)
{
	sfFloatRect rect;
	int x = 0;

	if (g->status_enter_zone == 1) {
		sfText_setString(g->text, "you enter in");
		rect = sfText_getGlobalBounds(g->text);
		x = (1600 - rect.width) / 2;
		draw_text(g, "you enter in :", x, 400);
	}
	sfText_setString(g->text, g->title_text);
	rect = sfText_getGlobalBounds(g->text);
	x = (1600 - rect.width) / 2;
	draw_text(g, g->title_text, x, 500);
}

void draw_game(p_game *g)
{
	sfTime timex;

	timex = sfClock_getElapsedTime(g->title_clock);
	if (g->boss_zone == 0) {
		draw_map(g, 1);
	} else if (g->zone > 3)
		draw_map(g, 3);
	else
		draw_map(g, 2);
	g->i_player.rect.left = g->player_direction * g->i_player.rect.width;
	sfSprite_setTextureRect(g->i_player.sprite, g->i_player.rect);
	sfRenderWindow_drawSprite(g->window, g->i_player.sprite, NULL);
	if (g->player_move == 2)
		draw_player_particules(g);
	if (timex.microseconds / 1000000 < 1.5 && g->title_text != NULL)
		draw_zone_name(g);
}
