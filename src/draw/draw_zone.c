/*
** EPITECH PROJECT, 2018
** draw zone
** File description:
** c file
*/

#include "my_rpg.h"

void draw_zone(p_game *g)
{
	if (g->boss_zone == 1) {
		draw_text(g, "Boss zone", 550, 750);
		return;
	}
	switch (g->actual_zone) {
		case 0:
			draw_text(g, "Start Zone", 550, 750);
			break;
		case 1:
			draw_text(g, "Lake Zone", 550, 750);
			break;
		case 2:
			draw_text(g, "Desert Zone", 550, 750);
			break;
		case 3:
			draw_text(g, "Snow Zone", 550, 750);
			break;
		default:
			draw_text(g, "Unknown Zone", 550, 750);
	}
}
