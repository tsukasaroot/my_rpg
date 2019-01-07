/*
** EPITECH PROJECT, 2018
** key get player name
** File description:
** c file
*/

#include "my_rpg.h"

void player_name_remove_last_char(p_game *g)
{
	char *name = NULL;
	int i = 0;

	if (g->player_name == NULL)
		return;
	if (my_strlen(g->player_name) == 1) {
		free(g->player_name);
		g->player_name = NULL;
		return;
	}
	name = malloc(sizeof(char) * my_strlen(g->player_name));
	while (g->player_name[i]) {
		name[i] = g->player_name[i];
		i++;
	}
	name[i - 1] = '\0';
	free(g->player_name);
	g->player_name = name;
}

void player_name_add_char(p_game *g, char c)
{
	char *name = NULL;
	int i = 0;

	if (g->player_name == NULL) {
		name = malloc(sizeof(char) * 2);
		name[0] = c;
		name[1] = '\0';
		g->player_name = name;
		return;
	}
	name = malloc(sizeof(char) * (my_strlen(g->player_name) + 2));
	while (g->player_name[i]) {
		name[i] = g->player_name[i];
		i++;
	}
	name[i] = c;
	name[i + 1] = '\0';
	free(g->player_name);
	g->player_name = name;
}

void key_get_player_name(p_game *g, sfEvent *event)
{
	if (event->key.code == sfKeyBack)
		player_name_remove_last_char(g);
	else if (event->key.code >= 0 && event->key.code <= 26) {
		if (my_strlen(g->player_name) <= 15)
			player_name_add_char(g, event->key.code + 'a');
	} else if (event->key.code == sfKeySpace) {
		if (my_strlen(g->player_name) <= 15)
			player_name_add_char(g, ' ');
	} else if (event->key.code == sfKeyReturn && g->player_name != NULL)
		g->status_intro = 2;
}
