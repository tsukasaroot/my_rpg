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

void my_event_check_key_released(p_game *g, sfEvent *event)
{
	if (event->type == sfEvtKeyReleased) {
		if (event->key.code == g->key_move_down)
			g->key_press_move_down = 0;
		else if (event->key.code == g->key_move_up)
			g->key_press_move_up = 0;
		else if (event->key.code == g->key_move_left)
			g->key_press_move_left = 0;
		else if (event->key.code == g->key_move_right)
			g->key_press_move_right = 0;
	}
}

void my_event_key_pressed(p_game *g, sfEvent *event)
{
	switch (g->status) {
		case 0:
			key_title_screen(g, event);
			break;
		case 1:
			key_start_menu(g, event);
			break;
		case 2:
			key_game(g, event);
			break;
		case 4:
			key_menu(g, event);
			break;
		case 6:
			key_get_player_name(g, event);
			break;
	}
}

void key_player_move(p_game *g)
{
	if (g->player_move == 2)
		return;
	if (g->key_press_move_up == 1)
		g->player_direction = 1;
	else if (g->key_press_move_down == 1)
		g->player_direction = 0;
	else if (g->key_press_move_left == 1)
		g->player_direction = 2;
	else if (g->key_press_move_right == 1)
		g->player_direction = 3;
}

void my_event(p_game *g)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(g->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(g->window);
		else if (event.type == sfEvtKeyPressed)
			my_event_key_pressed(g, &event);
		my_event_check_key_released(g, &event);
		my_event_click(g, &event);
	}
	key_player_move(g);
	if (g->key_press_move_up == 1 && g->player_move == 0)
		g->player_move = 1;
	if (g->key_press_move_down == 1 && g->player_move == 0)
		g->player_move = 1;
	if (g->key_press_move_left == 1 && g->player_move == 0)
		g->player_move = 1;
	if (g->key_press_move_right == 1 && g->player_move == 0)
		g->player_move = 1;
	my_event_check_button_pressed(g, &event);
}
