/*
** EPITECH PROJECT, 2018
** draw_start_menu
** File description:
** c file
*/

#include "my_rpg.h"

void draw_start_menu(p_game *g)
{
	set_img_relative_pos(g, &g->i_bt_start);
	set_img_relative_pos(g, &g->i_bt_load);
	set_img_relative_pos(g, &g->i_bt_option);
	set_img_relative_pos(g, &g->i_bt_quit);
	set_img_relative_pos(g, &g->i_start_menu);
	draw_button(g, &g->bt_start, &g->i_bt_start);
	draw_button(g, &g->bt_load, &g->i_bt_load);
	draw_button(g, &g->bt_option, &g->i_bt_option);
	draw_button(g, &g->bt_quit, &g->i_bt_quit);
	sfRenderWindow_drawSprite(g->window, g->i_start_menu.sprite, NULL);
}
