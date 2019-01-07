/*
** EPITECH PROJECT, 2018
** set img sprite
** File description:
** c file
*/

#include "my_rpg.h"

int set_img_sprite(p_img *img, const char *path)
{
	sfFloatRect size;

	img->texture = sfTexture_createFromFile(path, NULL);
	if (!img->texture)
		return (84);
	img->sprite = sfSprite_create();
	sfSprite_setTexture(img->sprite, img->texture, sfTrue);
	size = sfSprite_getLocalBounds(img->sprite);
	img->pos.x = 0;
	img->pos.y = 0;
	img->rect.top = 0;
	img->rect.left = 0;
	img->rect.width = size.width;
	img->rect.height = size.height;
	return (0);
}
