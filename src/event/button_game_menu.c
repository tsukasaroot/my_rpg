/*
** EPITECH PROJECT, 2018
** button game menu
** File description:
** c file
*/

#include "my_rpg.h"

void button_sub_menu_1(p_game *g, sfEvent *event)
{
	if (check_button(g, event, &g->bt_item, &g->i_bt_item) == 3)
		g->status_game_menu = 1;
	if (check_button(g, event, &g->bt_skills, &g->i_bt_skills) == 3)
		g->status_game_menu = 2;
	if (check_button(g, event, &g->bt_equip, &g->i_bt_equip) == 3)
		g->status_game_menu = 3;
}

void button_sub_menu_2(p_game *g, sfEvent *event)
{
	if (check_button(g, event, &g->bt_status, &g->i_bt_status) == 3)
		g->status_game_menu = 4;
	if (check_button(g, event, &g->bt_story, &g->i_bt_story) == 3)
		g->status_game_menu = 5;
	if (check_button(g, event, &g->bt_setup, &g->i_bt_setup) == 3)
		g->status_game_menu = 6;
}

void button_sub_menu_3(p_game *g, sfEvent *event)
{
	if (check_button(g, event, &g->bt_save, &g->i_bt_save) == 3)
		g->status_game_menu = 7;
	if (check_button(g, event, &g->bt_end, &g->i_bt_end) == 3) {
		reset_status(g);
		g->status = 0;
	}
	if (check_button(g, event, &g->bt_quit_m, &g->i_bt_quit_m) == 3) {
		reset_status(g);
		g->status = 2;
	}
}

void button_game_menu(p_game *g, sfEvent *event)
{
	if (g->status_game_menu == 0) {
		button_sub_menu_1(g, event);
		button_sub_menu_2(g, event);
		button_sub_menu_3(g, event);
	}
}
