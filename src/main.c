/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** main file
*/

#include "my_rpg.h"

int main(int argc, char **argv)
{
	char **map;
	int x = 0;
	int y = 0;

	if (argc != 2) {
		bad_argument(argc);
		return (84);
	}
	if (my_strcmp(argv[1], "-h")) {
		flag_h();
		return (0);
	} else {
		map = get_map(argv[1], &x, &y);
		if (map == NULL)
			return (0);
		game_loop(map, x, y);
		free_tab(map);
	}
	return (0);
}
