/*
** EPITECH PROJECT, 2018
** set img center
** File description:
** c file
*/

#include "my_rpg.h"

void set_img_center(p_game *g, p_img *img)
{
	sfVector2f center = sfView_getCenter(g->view);
	int x = 0;
	int y = 0;

	if (img->rect.width > 0 && img->rect.height > 0) {
		x = center.x - (img->rect.width / 2);
		y = center.y - (img->rect.height / 2);
		set_img_pos(img, x, y);
	}
}
