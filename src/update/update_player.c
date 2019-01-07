/*
** EPITECH PROJECT, 2018
** update player
** File description:
** c file
*/

#include "my_rpg.h"

void update_player_pos_y(p_game *g, int y)
{
	int i = sfTime_asMilliseconds(sfClock_getElapsedTime(g->player_clock));
	int test = g->i_player.pos.y;

	test = test % g->rect_map.height;
	if (i > 20) {
		if (test != 0) {
			g->i_player.pos.y += (g->rect_map.height / 8) * y;
			sfClock_restart(g->player_clock);
		} else {
			g->player_move = 0;
		}
	}
}

void update_player_pos_x(p_game *g, int x)
{
	int i = sfTime_asMilliseconds(sfClock_getElapsedTime(g->player_clock));
	int test = g->i_player.pos.x;

	test = test % g->rect_map.width;
	if (i > 20) {
		if (test != 0) {
			g->i_player.pos.x += (g->rect_map.width / 8) * x;
			sfClock_restart(g->player_clock);
		} else {
			g->player_move = 0;
		}
	}
}

void update_player_pos(p_game *g)
{
	switch (g->player_direction) {
		case 0:
			update_player_pos_y(g, 1);
			break;
		case 1:
			update_player_pos_y(g, -1);
			break;
		case 2:
			update_player_pos_x(g, -1);
			break;
		case 3:
			update_player_pos_x(g, 1);
			break;
	}
	sfSprite_setPosition(g->i_player.sprite, g->i_player.pos);
}

void update_player_start_moving(p_game *g)
{
	g->player_move = 2;
	sfClock_restart(g->player_clock);
	switch (g->player_direction) {
		case 0:
			g->i_player.pos.y += g->rect_map.height / 8;
			break;
		case 1:
			g->i_player.pos.y -= g->rect_map.height / 8;
			break;
		case 2:
			g->i_player.pos.x -= g->rect_map.width / 8;
			break;
		case 3:
			g->i_player.pos.x += g->rect_map.width / 8;
			break;
	}
	sfSprite_setPosition(g->i_player.sprite, g->i_player.pos);
}

void update_player(p_game *g)
{
	if (g->player_move == 1 && g->boss_zone == 0) {
		if (player_can_walk(g, g->map))
			update_player_start_moving(g);
	} else if (g->player_move == 1 && g->zone > 3) {
		if (player_can_walk(g, g->f_boss_map))
			update_player_start_moving(g);
	} else if (g->player_move == 1) {
		if (player_can_walk(g, g->boss_map))
			update_player_start_moving(g);
	} else if (g->player_move == 2) {
		update_player_pos(g);
		if (g->player_move == 0 && g->boss_zone == 0)
			check_player_case(g, g->map);
		else if (g->player_move == 0 && g->zone > 3)
			check_player_case(g, g->f_boss_map);
		else if (g->player_move == 0)
			check_player_case(g, g->boss_map);
	}
	update_player_animation(g);
}
