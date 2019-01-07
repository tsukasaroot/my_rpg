/*
** EPITECH PROJECT, 2018
** update_start_menu
** File description:
** c file
*/

#include "my_rpg.h"

void update_start_menu(p_game *g)
{
	draw_start_menu(g);
	if (g->status_start_menu == 1)
		draw_start_menu_load(g);
	else if (g->status_start_menu == 2)
		draw_start_menu_option(g);
	else if (g->status_start_menu == 3)
		draw_start_menu_key_option(g);
}
