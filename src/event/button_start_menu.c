/*
** EPITECH PROJECT, 2018
** button start menu
** File description:
** c file
*/

#include "my_rpg.h"

void button_start_menu_part_2(p_game *g, sfEvent *event)
{
	if (check_button(g, event, &g->bt_quit, &g->i_bt_quit) == 3)
		sfRenderWindow_close(g->window);
}

void button_start_menu(p_game *g, sfEvent *event)
{
	if (check_button(g, event, &g->bt_start, &g->i_bt_start) == 3) {
		reset_status(g);
		sfMusic_stop(g->music_ts);
		sfMusic_play(g->music_land);
		if (g->player_name == NULL)
			g->status = 6;
		else
			g->status = 2;
	}
	if (check_button(g, event, &g->bt_load, &g->i_bt_load) == 4)
		g->status_start_menu = 1;
	if (check_button(g, event, &g->bt_option, &g->i_bt_option) == 3)
		g->status_start_menu = 2;
	button_start_menu_part_2(g, event);
}
