/*
** EPITECH PROJECT, 2018
** draw_map
** File description:
** c file
*/

#include "my_rpg.h"

void draw_map_case(p_game *g, char c)
{
	if (c >= 48 && c <= 57) {
		g->rect_map.left = (c - 48) * g->rect_map.width;
		sfSprite_setTextureRect(g->s_map, g->rect_map);
		sfRenderWindow_drawSprite(g->window, g->s_map, NULL);
	} else if (c >= 65 && c <= 90) {
		g->rect_map.left = (c - 65 + 10) * g->rect_map.width;
		sfSprite_setTextureRect(g->s_map, g->rect_map);
		sfRenderWindow_drawSprite(g->window, g->s_map, NULL);
	} else if (c >= 97 && c <= 122) {
		g->rect_map.left = (c - 97 + 36) * g->rect_map.width;
		sfSprite_setTextureRect(g->s_map, g->rect_map);
		sfRenderWindow_drawSprite(g->window, g->s_map, NULL);
	}
}

void draw_map(p_game *g)
{
	int x = 0;
	int y = 0;

	while (g->map && g->map[y]) {
		x = 0;
		g->p_map.y = y * g->rect_map.height;
		while (g->map[y][x]) {
			g->p_map.x = x * g->rect_map.width;
			sfSprite_setPosition(g->s_map, g->p_map);
			draw_map_case(g, g->map[y][x]);
			x++;
		}
		y++;
	}
}
