/*
** EPITECH PROJECT, 2018
** draw_map
** File description:
** c file
*/

#include "my_rpg.h"

void check_pnj_case(p_game *g, int x, int y)
{
	if (g->map[y][x] >= 'A' && g->map[y][x] <= 'Z') {
		set_img_pos(&g->i_pnj[g->map[y][x] - 'A'], x * 64, y * 64);
		draw_sprite(g, g->i_pnj[g->map[y][x] - 'A'].sprite);
	}
}

void draw_pnj(p_game *g)
{
	int x = g->i_player.pos.x / 64 - 20;
	int y = g->i_player.pos.y / 64 - 20;
	int x_max = g->i_player.pos.x / 64 + 20;
	int y_max = g->i_player.pos.y / 64 + 20;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	while (y < y_max && g->map[y] != NULL) {
		x = 0;
		while (x < x_max && g->map[y][x] != '\0') {
			check_pnj_case(g, x, y);
			x++;
		}
		y++;
	}
}

void draw_map(p_game *g, int map)
{
	if (map == 1) {
		draw_sprite(g, g->s_map);
		draw_pnj(g);
	} else if (map == 2)
		draw_sprite(g, g->s_boss_map);
	else if (map == 3)
		draw_sprite(g, g->s_f_boss_map);
}
