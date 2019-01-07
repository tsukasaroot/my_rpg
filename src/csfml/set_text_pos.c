/*
** EPITECH PROJECT, 2018
** set text pos
** File description:
** c file
*/

#include "my_rpg.h"

void set_text_pos(p_game *g, int x, int y)
{
	sfVector2f center = sfView_getCenter(g->view);
	sfVector2f size = sfView_getSize(g->view);
	sfVector2f pos;

	pos.x = x + center.x - size.x / 2;
	pos.y = y + center.y - size.y / 2;
	sfText_setPosition(g->text, pos);
}
