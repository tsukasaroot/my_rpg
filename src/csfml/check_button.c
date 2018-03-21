/*
** EPITECH PROJECT, 2018
** check button
** File description:
** c file
*/

#include "my_rpg.h"

int check_button_event(sfEvent *event, p_button *btn)
{
	if (event->type == sfEvtMouseButtonPressed) {
		btn->status = 2;
		sfClock_restart(btn->clock);
		return (2);
	} else {
		btn->status = 1;
		return (1);
	}
	return (0);
}

int check_button(p_game *g, sfEvent *event, p_button *btn, p_img *img)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(g->window);
	int y = 0;

	if (btn->status == 2) {
		y = sfTime_asMilliseconds(sfClock_getElapsedTime(btn->clock));
		if (y >= 300) {
			btn->status = 3;
			return (3);
		}
		return (2);
	}
	btn->status = 0;
	if (pos.x >= img->pos.x && pos.x <= img->pos.x + img->rect.width) {
		y = img->pos.y;
		if (pos.y >= y && pos.y <= y + img->rect.height)
			return (check_button_event(event, btn));
	}
	return (0);
}
