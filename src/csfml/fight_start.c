/*
** EPITECH PROJECT, 2018
** fight_start
** File description:
** c file
*/

#include "my_rpg.h"

void fight_add_mob(p_game *g, p_mob **mob, int nb)
{
	p_mob *new = malloc(sizeof(p_mob));

	*mob = new;
	new->sprite = nb;
	new->next = NULL;
	new->ATK = g->class->ATK;
	if (nb == 2)
		new->ATK = new->ATK * 3;
	new->HP = 100;
}

void set_player_hp(t_class_stat *c)
{
	if (c == NULL)
		return;
	c->HP = c->HEALTH;
	set_player_hp(c->next);
}

void init_fight_start(p_game *g, int mob)
{
	g->status = 3;
	g->fight_turn = 0;
	g->fight_mob = mob;
	g->nb_of_mob = 1;
	fight_add_mob(g, &g->mob, 1);
	sfMusic_stop(g->music_land);
	sfMusic_play(g->music_fight);
	g->p_mob1.x = 300;
	g->p_mob1.y = 750;
	g->p_mob2.x = 200;
	g->p_mob2.y = 800;
	g->p_mob3.x = 300;
	g->p_mob3.y = 750;
	g->p_mob4.x = 400;
	g->p_mob4.y = 700;
	g->p_char1.x = 1000;
	g->p_char1.y = 850;
	g->p_char2.x = 1000;
	g->p_char2.y = 750;
	g->p_char3.x = 1000;
	g->p_char3.y = 650;
	g->p_char4.x = 1000;
	g->p_char4.y = 550;
}

void fight_start(p_game *g, int mob)
{
	g->status = 3;
	g->fight_turn = 0;
	g->fight_mob = mob;
	g->nb_of_mob = 1;
	fight_add_mob(g, &g->mob, mob);
	sfMusic_stop(g->music_land);
	sfMusic_play(g->music_fight);
	init_fight_start(g, mob);
	set_player_hp(g->class);
}
