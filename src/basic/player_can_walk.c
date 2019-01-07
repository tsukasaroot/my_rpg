/*
** EPITECH PROJECT, 2018
** player can walk
** File description:
** c file
*/

#include "my_rpg.h"

void player_teleportation(p_game *g)
{
	if (g->boss_zone == 0 && g->i_player.pos.y < 75 * 64) {
		g->i_player.pos.x = 77 * 64;
		g->i_player.pos.y = 82 * 64;
	} else if (g->boss_zone == 0) {
		g->i_player.pos.x = 76 * 64;
		g->i_player.pos.y = 72 * 64;
	} else {
		if (g->i_player.pos.y < 25 * 64) {
			g->i_player.pos.x = 8 * 64;
			g->i_player.pos.y = 27 * 64;
		} else {
			g->i_player.pos.x = 40 * 64;
			g->i_player.pos.y = 5 * 64;
		}
	}
	sfSprite_setPosition(g->i_player.sprite, g->i_player.pos);
}

int player_can_walk_part3(p_game *g, char **map, int x, int y)
{
	if (g->player_direction == 3) {
		if ((map[y][x + 1] >= '0' && map[y][x + 1] <= '2') ||
			(map[y][x + 1] >= 'B' && map[y][x + 1] <= 'Z'))
			return (1);
		if (map[y][x + 1] >= 'a' && map[y][x + 1] <= 'a' + g->zone &&
			g->zone < 5)
			return (1);
		else if (map[y][x + 1] == '4')
			player_teleportation(g);
		else if (map[y][x + 1] >= 'a')
			player_cant_enter_zone(g);
	}
	g->player_move = 0;
	return (0);
}

int player_can_walk_part2(p_game *g, char **map, int x, int y)
{
	if (g->player_direction == 2 && x - 1 >= 0) {
		if ((map[y][x - 1] >= '0' && map[y][x - 1] <= '2') ||
			(map[y][x - 1] >= 'B' && map[y][x - 1] <= 'Z'))
			return (1);
		if (map[y][x - 1] >= 'a' && map[y][x - 1] <= 'a' + g->zone)
			return (1);
		else if (map[y][x - 1] == '4')
			player_teleportation(g);
		else if (map[y][x - 1] >= 'a')
			player_cant_enter_zone(g);
	} else
		return (player_can_walk_part3(g, map, x, y));
	g->player_move = 0;
	return (0);
}

int util_player_can_walk(p_game *g, char **map, int x, int y)
{
	if ((map[y + 1][x] >= '0' && map[y + 1][x] <= '2') ||
	(map[y + 1][x] >= 'B' && map[y + 1][x] <= 'Z'))
		return (1);
	if (map[y + 1][x] >= 'a' && map[y + 1][x] <= 'a' + g->zone)
		return (1);
	else if (map[y + 1][x] == '4')
		player_teleportation(g);
	else if (map[y + 1][x] >= 'a')
		player_cant_enter_zone(g);
	return (0);
}

int player_can_walk(p_game *g, char **map)
{
	int x = g->i_player.pos.x / g->rect_map.width;
	int y = g->i_player.pos.y / g->rect_map.height;

	if (g->player_direction == 0 && map[y + 1]) {
		if (util_player_can_walk(g, map, x, y) == 1)
			return (1);
	} else if (g->player_direction == 1 && y - 1 >= 0) {
		if ((map[y - 1][x] >= '0' && map[y - 1][x] <= '2') ||
			(map[y - 1][x] >= 'B' && map[y - 1][x] <= 'Z'))
			return (1);
		if (map[y - 1][x] >= 'a' && map[y - 1][x] <= 'a' + g->zone)
			return (1);
		else if (map[y - 1][x] == '4')
			player_teleportation(g);
		else if (map[y - 1][x] >= 'a')
			player_cant_enter_zone(g);
	} else
		return (player_can_walk_part2(g, map, x, y));
	g->player_move = 0;
	return (0);
}
