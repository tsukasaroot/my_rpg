/*
** EPITECH PROJECT, 2018
** event click skills menu
** File description:
** c file
*/

#include "my_rpg.h"

void add_skill(p_game *g)
{
	if (g->skill_select >= 1 && g->skill_select <= 6) {
		g->spells[0].ATK_MOD[g->skill_select] += 1;
	}
}

int count_skills(p_game *g)
{
	int i = 0;

	i += g->spells[0].ATK_MOD[0] + g->spells[0].ATK_MOD[1];
	i += g->spells[0].ATK_MOD[2] + g->spells[0].ATK_MOD[3];
	i += g->spells[0].ATK_MOD[3] + g->spells[0].ATK_MOD[4];
	i += g->spells[0].ATK_MOD[5] + g->spells[0].ATK_MOD[6];
	i += g->spells[0].ATK_MOD[7] + g->spells[0].ATK_MOD[8];
	i += g->spells[0].ATK_MOD[9] + g->spells[0].ATK_MOD[10];
	i += g->spells[0].ATK_MOD[11];
	return (i);
}

void event_click_skills_menu(p_game *g, sfEvent *event)
{
	int x = event->mouseButton.x;
	int y = event->mouseButton.y;

	if (x > 395 && x < 580) {
		if (y > 295 && y < 325)
			g->skill_select = 1;
		else if (y > 345 && y < 375)
			g->skill_select = 2;
		else if (y > 395 && y < 425)
			g->skill_select = 3;
		else if (y > 445 && y < 475)
			g->skill_select = 4;
		else if (y > 495 && y < 525)
			g->skill_select = 5;
		else if (y > 545 && y < 575)
			g->skill_select = 6;
	}
	if (g->level > count_skills(g) + 1 &&
		check_button(g, event, &g->bt_plus, &g->i_bt_plus) == 3)
		add_skill(g);
}
