/*
** EPITECH PROJECT, 2018
** game_loop
** File description:
** c file
*/

#include "my_rpg.h"

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
		//update_fight(g);
		break;
	case 4 :
		update_menu(g);
		break;
	}
}

int game_loop(char **map, int x, int y)
{
	p_game g;

	g.map = map;
	if (game_init(&g, x, y) == 84)
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
