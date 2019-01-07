/*
** EPITECH PROJECT, 2018
** game_init
** File description:
** c file
*/

#include "my_rpg.h"

int final_init1(p_game *g, char *name, sfVideoMode mode)
{
	init1(g);
	if (init2(g) == 84)
		return (84);
	if (init3(g) == 84)
		return (84);
	if (init4(g) == 84)
		return (84);
	if (init5(g, name, mode) == 84)
		return (84);
	if (init6(g) == 84)
		return (84);
	if (init7(g) == 84)
		return (84);
	if (init8(g) == 84)
		return (84);
	if (init9(g) == 84)
		return (84);
	if (init10(g) == 84)
		return (84);
	return (0);
}

int final_init2(p_game *g)
{
	if (init11(g) == 84)
		return (84);
	if (init12(g) == 84)
		return (84);
	if (init13(g) == 84)
		return (84);
	if (init14(g) == 84)
		return (84);
	if (init15(g) == 84)
		return (84);
	if (set_img_sprite(&g->i_char[0], "image/char/knight/1.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_char[1], "image/char/magician/1.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_char[2], "image/char/healer/1.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_char[3], "image/char/warrior/1.png") == 84)
		return (84);
	return (0);
}

int game_init(p_game *g, int x, int y, int x2)
{
	char *name = "Isekai wa ore to kanojo o sukuu";
	sfVideoMode mode = {1600, 900, 32};
	int y2 = 0;
	int x3 = 0;
	int y3 = 0;

	if (final_init1(g, name, mode) == 84)
		return (84);
	if (final_init2(g) == 84)
		return (84);
	x = x * g->rect_map.width;
	y = y * g->rect_map.height;
	set_img_pos(&g->i_player, x, y);
	g->boss_map = get_map("map/boss", &x2, &y2);
	g->f_boss_map = get_map("map/fboss", &x3, &y3);
	g->p_boss_map.x = x2 * g->rect_map.width;
	g->p_boss_map.y = y2 * g->rect_map.height;
	g->p_fboss_map.x = x3 * g->rect_map.width;
	g->p_fboss_map.y = y3 * g->rect_map.height;
	return (0);
}
