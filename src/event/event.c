/*
** EPITECH PROJECT, 2018
** event
** File description:
** event file
*/

#include "my_rpg.h"

void my_event_check_button_pressed(p_game *g, sfEvent *event)
{
	switch (g->status) {
		case 1:
			button_start_menu(g, event);
			break;
		case 4:
			button_game_menu(g, event);
			break;
	}
}

void my_event_key_pressed(p_game *g, sfEvent *event)
{
	switch (g->status) {
		case 0:
			key_title_screen(g, event);
			break;
		case 2:
			key_game(g, event);
			break;
		case 4:
			key_menu(g, event);
			break;
	}
}

void my_event(p_game *g)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(g->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(g->window);
		else if (event.type == sfEvtKeyPressed)
			my_event_key_pressed(g, &event);
	}
	my_event_check_button_pressed(g, &event);
}
