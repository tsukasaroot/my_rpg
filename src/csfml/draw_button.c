/*
** EPITECH PROJECT, 2018
** draw button
** File description:
** c file
*/

#include "my_rpg.h"

void draw_button(p_game *g, p_button *btn, p_img *img)
{
	if (btn->status < 3)
		img->rect.left = btn->status * img->rect.width;
	else
		img->rect.left = 0;
	sfSprite_setTextureRect(img->sprite, img->rect);
	sfRenderWindow_drawSprite(g->window, img->sprite, NULL);
}
