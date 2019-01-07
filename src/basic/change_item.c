/*
** EPITECH PROJECT, 2018
** change item
** File description:
** basic functions
*/

#include "my_rpg.h"

void change_item_part2(p_game *g)
{
	int tmp = 0;

	if (g->itm_select->id == 3) {
		tmp = g->select_perso->chestplate;
		g->select_perso->chestplate = g->itm_select->power;
		g->itm_select->power = tmp;
	} if (g->itm_select->id == 2 || g->itm_select->id == 0) {
		tmp = g->select_perso->weapon_pow;
		g->select_perso->weapon_pow = g->itm_select->power;
		g->itm_select->power = tmp;
	} else if (g->itm_select->id == 1) {
		tmp = g->select_perso->shield;
		g->select_perso->shield = g->itm_select->power;
		g->itm_select->power = tmp;
	}
}

void change_item(p_game *g)
{
	int tmp = 0;

	if (g->itm_select->id == 5) {
		tmp = g->select_perso->gloves;
		g->select_perso->gloves = g->itm_select->power;
		g->itm_select->power = tmp;
	} else if (g->itm_select->id == 4) {
		tmp = g->select_perso->helmet;
		g->select_perso->helmet = g->itm_select->power;
		g->itm_select->power = tmp;
	} else {
		change_item_part2(g);
	}
}
