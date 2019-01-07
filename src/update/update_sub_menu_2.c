/*
** EPITECH PROJECT, 2018
** update_menu
** File description:
** c file
*/

#include "my_rpg.h"

void update_menu_skill(p_game *g)
{
	set_img_center(g, &g->i_dark_screen);
	sfRenderWindow_drawSprite(g->window, g->i_dark_screen.sprite, NULL);
	draw_menu_skill(g);
}

void update_menu_setup(p_game *g)
{
	set_img_center(g, &g->i_dark_screen);
	sfRenderWindow_drawSprite(g->window, g->i_dark_screen.sprite, NULL);
	draw_menu_setup(g);
	if (g->status_start_menu == 1)
		g->status_game_menu = 0;
	if (g->status_start_menu == 2)
		draw_start_menu_option(g);
	else if (g->status_start_menu == 3)
		draw_start_menu_key_option(g);
}
