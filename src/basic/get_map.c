/*
** EPITECH PROJECT, 2018
** get_map
** File description:
** c file
*/

#include "my_rpg.h"

int my_tablen(char **tab)
{
	int i = 0;

	if (tab == 0)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char **map_add_line(char **map, char *line)
{
	int i = my_tablen(map);
	char **new_map = malloc(sizeof(char *) * (i + 2));

	i = 0;
	while (map && map[i]) {
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = my_strcpy(line);
	new_map[i + 1] = NULL;
	return (new_map);
}

void get_map_pos(int fd, int *x, int *y)
{
	char *line;

	if ((line = get_nextline(fd)) != NULL) {
		*x = get_nbr(line);
		free(line);
		if ((line = get_nextline(fd)) != NULL) {
			*y = get_nbr(line);
			free(line);
		}
	}
}

char **get_map(char *name, int *x, int *y)
{
	int fd = open(name, O_RDONLY);
	char *line = NULL;
	char **map = NULL;
	int i = 0;

	if (fd == 0)
		return (NULL);
	get_map_pos(fd, x, y);
	if (*x <= 0 && *y <= 0)
		return (NULL);
	while ((line = get_nextline(fd)) != NULL) {
		map = map_add_line(map, line);
		free(line);
		i++;
	}
	return (map);
}

void player_cant_enter_zone(p_game *g)
{
	if (g->title_text != NULL)
		free(g->title_text);
	g->title_text = my_strcpy("you can't access this area !");
	g->status_enter_zone = 0;
	sfClock_restart(g->title_clock);
}
