/*
** EPITECH PROJECT, 2018
** free img
** File description:
** c file
*/

#include "my_rpg.h"

void free_img(p_img *img)
{
	if (img != NULL) {
		if (img->texture)
			sfTexture_destroy(img->texture);
		if (img->sprite)
			sfSprite_destroy(img->sprite);
	}
}
