/*
** EPITECH PROJECT, 2018
** set img rect size
** File description:
** c file
*/

#include "my_rpg.h"

int set_img_rect_size(p_img *img, int width, int height)
{
	img->rect.height = height;
	img->rect.width = width;
	sfSprite_setTextureRect(img->sprite, img->rect);
	return (0);
}
