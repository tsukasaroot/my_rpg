/*
** EPITECH PROJECT, 2018
** player interaction
** File description:
** c file
*/

#include "my_rpg.h"

void player_interaction_get_case(p_game *g, int *x, int *y)
{
	if (g->player_direction == 0 || g->player_direction == 1) {
		if (g->player_direction == 0 && g->map[*y + 1])
			*y += 1;
		else if (g->player_direction == 1 && *y >= 0)
			*y -= 1;
	} else if (g->player_direction == 2 || g->player_direction == 3) {
		if (g->player_direction == 2 && *x >= 0)
			*x -= 1;
		else if (g->player_direction == 3 && g->map[*y][*x + 1])
			*x += 1;
	}
}

void player_interaction(p_game *g)
{
	int x = g->i_player.pos.x / g->rect_map.width;
	int y = g->i_player.pos.y / g->rect_map.height;

	player_interaction_get_case(g, &x, &y);
	if (g->boss_zone == 1)
		return;
	if (g->map[y][x] == 'A')
		wrapper(g, "scripts/S_01.sc", g->player_name);
}
