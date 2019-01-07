/*
** EPITECH PROJECT, 2018
** check_player_case.c
** File description:
** c file
*/

#include "my_rpg.h"

void check_player_case_map(p_game *g)
{
	g->boss_zone = 1;
	g->p_map_old.x = g->i_player.pos.x;
	g->p_map_old.y = g->i_player.pos.y;
	if (g->zone > 3) {
		g->i_player.pos.x = g->p_fboss_map.x;
		g->i_player.pos.y = g->p_fboss_map.y;
	} else {
		g->i_player.pos.x = g->p_boss_map.x;
		g->i_player.pos.y = g->p_boss_map.y;
	}
	sfSprite_setPosition(g->i_player.sprite, g->i_player.pos);
}

void check_player_case_boss_zone(p_game *g)
{
	if (g->zone > 3)
		fight_start(g, 3);
	else
		fight_start(g, 2);
	g->boss_zone = 0;
	g->i_player.pos = g->p_map_old;
	g->zone++;
	sfSprite_setPosition(g->i_player.sprite, g->i_player.pos);
}

void player_enter_zone_get_zone(p_game *g)
{
	switch (g->actual_zone) {
		case 0:
			g->title_text = my_strcpy("Start Zone");
			break;
		case 1:
			g->title_text = my_strcpy("Lake Zone");
			break;
		case 2:
			g->title_text = my_strcpy("Desert Zone");
			break;
		case 3:
			g->title_text = my_strcpy("Snow Zone");
			break;
		default:
			g->title_text = my_strcpy("Unknown Zone");
	}
}

void player_enter_zone(p_game *g)
{
	if (g->title_text != NULL)
		free(g->title_text);
	if (g->boss_zone == 1) {
		g->title_text = my_strcpy("Boss Zone");
		g->status_enter_zone = 1;
		sfClock_restart(g->title_clock);
		return;
	}
	player_enter_zone_get_zone(g);
	g->status_enter_zone = 1;
	sfClock_restart(g->title_clock);
}

void check_player_case(p_game *g, char **map)
{
	int x = g->i_player.pos.x / g->rect_map.width;
	int y = g->i_player.pos.y / g->rect_map.height;

	if (map[y][x] >= 'B' && map[y][x] <= 'Z') {
		g->count_tx = 0;
		g->status = 5;
	} else if (map[y][x] == '2') {
		if (g->boss_zone == 0)
			check_player_case_map(g);
		else
			check_player_case_boss_zone(g);
		player_enter_zone(g);
	} else if (map[y][x] >= 'a' && map[y][x] <= 'a' + g->zone) {
		if (g->actual_zone != map[y][x] - 'a') {
			g->actual_zone = map[y][x] - 'a';
			player_enter_zone(g);
		}
	}
}
