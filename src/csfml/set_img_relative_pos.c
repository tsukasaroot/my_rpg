/*
** EPITECH PROJECT, 2018
** set img relative pos
** File description:
** c file
*/

#include "my_rpg.h"

void set_img_relative_pos(p_game *g, p_img *img)
{
	sfVector2f center = sfView_getCenter(g->view);
	sfVector2f size = sfView_getSize(g->view);

	img->relative_pos.x = img->pos.x + center.x - size.x / 2;
	img->relative_pos.y = img->pos.y + center.y - size.y / 2;
	sfSprite_setPosition(img->sprite, img->relative_pos);
}
