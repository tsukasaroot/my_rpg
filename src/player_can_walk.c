/*
** EPITECH PROJECT, 2018
** player can walk
** File description:
** c file
*/

#include "my_rpg.h"

int player_can_walk_part2(p_game *g, int x, int y)
{
	if (g->player_direction == 2 && x - 1 >= 0) {
		if (g->map[y][x - 1] >= 'a' && g->map[y][x - 1] <= 'z')
			return (1);
	} else if (g->player_direction == 3) {
		if (g->map[y][x + 1] >= 'a' && g->map[y][x + 1] <= 'z')
			return (1);
	}
	return (0);
}

int player_can_walk(p_game *g)
{
	int x = g->i_player.pos.x / g->rect_map.width;
	int y = g->i_player.pos.y / g->rect_map.height;

	if (g->player_direction == 0) {
		if (g->map[y + 1][x] >= 'a' && g->map[y + 1][x] <= 'z')
			return (1);
	} else if (g->player_direction == 1 && y - 1 >= 0) {
		if (g->map[y - 1][x] >= 'a' && g->map[y - 1][x] <= 'z')
			return (1);
	} else
		return (player_can_walk_part2(g, x, y));
	return (0);
}
