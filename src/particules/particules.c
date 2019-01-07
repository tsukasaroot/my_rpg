/*
** EPITECH PROJECT, 2018
** particules
** File description:
** c file
*/

#include "my_rpg.h"

int draw_player_particules_x(p_game *g, t_particules *parts, int i, int timex)
{
	int x = 0;
	int y = 0;

	if (parts == NULL)
		return (i);
	if (g->player_direction == 2 || g->player_direction == 0)
		parts->x = (timex - parts->last_time) / 5 % 64;
	else
		parts->x = (timex - parts->last_time) / 5 % 64 * -1;
	parts->y = (parts->x + 1) / 2 * -1;
	x = g->i_player.pos.x + parts->x;
	y = g->i_player.pos.y + parts->y + 64;
	set_img_pos(&g->i_parts, x, y);
	draw_sprite(g, g->i_parts.sprite);
	return (draw_player_particules_x(g, parts->next, i + 1, timex));
}

void add_player_particules(p_game *g, t_particules **parts, int timex)
{
	t_particules *new = *parts;

	if (new != NULL)
		return (add_player_particules(g, &new->next, timex));
	new = malloc(sizeof(t_particules));
	new->x = 0;
	new->y = 0;
	new->time = timex;
	new->last_time = timex;
	new->next = NULL;
	*parts = new;
	g->last_parts = timex;

}

void draw_player_particules(p_game *g)
{
	int y = sfTime_asMilliseconds(sfClock_getElapsedTime(g->parts_clock));
	int i = 0;
	t_particules *new = NULL;

	i = draw_player_particules_x(g, g->parts, i, y);
	if (i < 6 && g->last_parts + 300 < y) {
		add_player_particules(g, &g->parts, y);
	}
	if (g->parts != NULL && y - g->parts->last_time > 600) {
		new = g->parts->next;
		free(g->parts);
		g->parts = new;
	}
}
