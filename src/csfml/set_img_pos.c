/*
** EPITECH PROJECT, 2018
** set img pos
** File description:
** c file
*/

#include "my_rpg.h"

int set_img_pos(p_img *img, int x, int y)
{
	img->pos.x = x;
	img->pos.y = y;
	sfSprite_setPosition(img->sprite, img->pos);
	return (0);
}
