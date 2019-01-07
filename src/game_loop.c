/*
** EPITECH PROJECT, 2018
** game_loop
** File description:
** c file
*/

#include "my_rpg.h"

void intro(p_game *g)
{
	static int boo = 0;

	if (boo == 0) {
		sfRenderWindow_clear(g->window, sfBlack);
		sfRenderWindow_display(g->window);
		wrapper(g, "scripts/S_00.sc", g->player_name);
		boo++;
	}
}

void update_rpg_part2(p_game *g)
{
	switch (g->status) {
	case 5:
		update_transition_battle(g);
		break;
	case 6:
		update_intro(g);
		break;
	case 7:
		intro(g);
		g->status = 6;
		break;
	}
}

void update_rpg(p_game *g)
{
	switch (g->status) {
	case 0 :
		update_title_screen(g);
		break;
	case 1 :
		update_start_menu(g);
		break;
	case 2 :
		update_game(g);
		break;
	case 3 :
		update_fight(g);
		break;
	case 4 :
		update_menu(g);
		break;
	default:
		update_rpg_part2(g);
		break;
	}
}

int game_loop(char **map, int x, int y)
{
	p_game g;

	g.map = map;
	if (set_class(&g) == 84)
		return (84);
	if (game_init(&g, x, y, 0) == 84)
		return (84);
	while (sfRenderWindow_isOpen(g.window)) {
		sfRenderWindow_clear(g.window, sfBlack);
		my_event(&g);
		update_rpg(&g);
		sfRenderWindow_display(g.window);
	}
	game_destroy(&g);
	return (0);
}
