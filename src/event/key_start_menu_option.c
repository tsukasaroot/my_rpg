/*
** EPITECH PROJECT, 2018
** key start menu option
** File description:
** c file
*/

#include "my_rpg.h"

void key_start_menu_option_1(p_game *g, sfEvent *event)
{
	switch (event->key.code) {
		case sfKeyLeft:
			if (g->music_volume > 10)
				g->music_volume -= 10;
			else
				g->music_volume = 0;
			set_volume(g);
			break;
		case sfKeyRight:
			if (g->music_volume < 90)
				g->music_volume += 10;
			else
				g->music_volume = 100;
			set_volume(g);
			break;
		default:
			break;
	}
}

void key_start_menu_option_2(p_game *g, sfEvent *event)
{
	if (event->key.code == sfKeyReturn) {
		g->status_start_menu = 3;
		g->option_select = 1;
	}
}

void key_start_menu_option_nb(p_game *g, sfEvent *event)
{
	if (g->option_select == 1)
		key_start_menu_option_1(g, event);
	else if (g->option_select == 2)
		key_start_menu_option_2(g, event);
}

void key_start_menu_option(p_game *g, sfEvent *event)
{
	switch (event->key.code) {
		case sfKeyEscape:
			g->status_start_menu = 0;
			g->option_select = 1;
			break;
		case sfKeyUp:
			if (g->option_select > 1)
				g->option_select -= 1;
			break;
		case sfKeyDown:
			if (g->option_select < 2)
				g->option_select += 1;
			break;
		default:
			key_start_menu_option_nb(g, event);
			break;
	}
}
