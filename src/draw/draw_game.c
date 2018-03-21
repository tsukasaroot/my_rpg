/*
** EPITECH PROJECT, 2018
** draw_game
** File description:
** c file
*/

#include "my_rpg.h"

void draw_game(p_game *g)
{
	draw_map(g);
	g->i_player.rect.left = g->player_direction * g->i_player.rect.width;
	sfSprite_setTextureRect(g->i_player.sprite, g->i_player.rect);
	sfRenderWindow_drawSprite(g->window, g->i_player.sprite, NULL);
}
