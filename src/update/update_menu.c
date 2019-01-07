/*
** EPITECH PROJECT, 2018
** update_menu
** File description:
** c file
*/

#include "my_rpg.h"

void update_menu(p_game *g)
{
	draw_game(g);
	draw_menu(g);
	update_sub_menu(g);
}

void update_sub_menu_part2(p_game *g)
{
	switch (g->status_game_menu) {
		case 6 :
			update_menu_setup(g);
			break;
		case 7 :
			update_menu_save(g);
			break;
	}
}

void update_sub_menu(p_game *g)
{
	switch (g->status_game_menu) {
		case 1 :
			update_menu_item(g);
			break;
		case 2 :
			update_menu_skill(g);
			break;
		case 3 :
			update_menu_equip(g);
			break;
		case 4 :
			update_menu_status(g);
			break;
		case 5 :
			update_menu_story(g);
			break;
		default:
			update_sub_menu_part2(g);
			break;
	}
}
