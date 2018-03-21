/*
** EPITECH PROJECT, 2018
** draw nbr
** File description:
** c file
*/

#include "my_rpg.h"

void draw_nbr(p_game *g, p_img *img, unsigned int nb, sfVector2f pos)
{
	sfFloatRect size = sfSprite_getLocalBounds(img->sprite);

	while (nb >= 10) {
		img->rect.left = nb % 10 * size.width;
		sfSprite_setTextureRect(img->sprite, img->rect);
		pos.x -= size.width;
		set_img_pos(img, pos.x, pos.y);
		set_img_relative_pos(g, img);
		sfRenderWindow_drawSprite(g->window, img->sprite, NULL);
		nb /= 10;
	}
	img->rect.left = nb * size.width;
	sfSprite_setTextureRect(img->sprite, img->rect);
	pos.x -= size.width;
	set_img_pos(img, pos.x, pos.y);
	set_img_relative_pos(g, img);
	sfRenderWindow_drawSprite(g->window, img->sprite, NULL);
}
