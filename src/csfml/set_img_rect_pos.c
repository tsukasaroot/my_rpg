/*
** EPITECH PROJECT, 2018
** set img rect pos
** File description:
** c file
*/

#include "my_rpg.h"

int set_img_rect_pos(p_img *img, int top, int left)
{
	img->rect.top = top;
	img->rect.left = left;
	sfSprite_setTextureRect(img->sprite, img->rect);
	return (0);
}
