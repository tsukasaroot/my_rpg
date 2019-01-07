/*
** EPITECH PROJECT, 2018
** draw sprtie
** File description:
** c file
*/

#include "my_rpg.h"

void draw_sprite(p_game *g, sfSprite *sprite)
{
	sfRenderWindow_drawSprite(g->window, sprite, NULL);
}
