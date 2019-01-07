/*
** EPITECH PROJECT, 2018
** update fight
** File description:
** c file
*/

#include "my_rpg.h"

void update_player_1(p_game *g, int timex)
{
	if (g->class->HP <= 0) {
		g->fight_turn++;
		return;
	}
	if (g->p_char1.x > 700 && timex > g->last_parts + 30) {
		g->p_char1.x -= 10;
		g->last_parts = timex;
	} else if (g->p_char1.x <= 700) {
		g->p_char1.x = 1000;
		g->p_char1.y = 850;
		g->mob->HP -= g->class->ATK;
		g->fight_turn++;
	}
}

void update_player_2(p_game *g, int timex)
{
	if (g->class->next->HP <= 0) {
		g->fight_turn++;
		return;
	}
	if (g->p_char2.x > 700 && timex > g->last_parts + 30) {
		g->p_char2.x -= 10;
		g->last_parts = timex;
	} else if (g->p_char2.x <= 700) {
		g->p_char2.x = 1000;
		g->p_char2.y = 750;
		g->mob->HP -= g->class->next->ATK;
		g->fight_turn++;
	}
}

void update_player_3(p_game *g, int timex)
{
	if (g->class->next->next->HP <= 0) {
		g->fight_turn++;
		return;
	}
	if (g->p_char3.x > 700 && timex > g->last_parts + 30) {
		g->p_char3.x -= 10;
		g->last_parts = timex;
	} else if (g->p_char3.x <= 700) {
		g->p_char3.x = 1000;
		g->p_char3.y = 650;
		g->mob->HP -= g->class->next->next->ATK;
		g->fight_turn++;
	}
}

void update_player_4(p_game *g, int timex)
{
	if (g->class->next->next->next->HP <= 0) {
		g->fight_turn++;
		return;
	}
	if (g->p_char4.x > 700 && timex > g->last_parts + 30) {
		g->p_char4.x -= 10;
		g->last_parts = timex;
	} else if (g->p_char4.x <= 700) {
		g->p_char4.x = 1000;
		g->p_char4.y = 550;
		g->mob->HP -= g->class->next->next->next->ATK;
		g->fight_turn++;
	}
}

void update_mob(p_game *g, int timex)
{
	if (g->p_mob1.x < 700 && timex > g->last_parts + 30) {
		g->p_mob1.x += 10;
		g->last_parts = timex;
	} else if (g->p_mob1.x >= 700) {
		g->p_mob1.x = 300;
		g->p_mob1.y = 750;
		g->fight_turn = 0;
		if (g->class->next->next->next->HP > 0)
			g->class->next->next->next->HP -= g->mob->ATK;
		else if (g->class->next->next->HP > 0)
			g->class->next->next->HP -= g->mob->ATK;
		else if (g->class->next->HP > 0)
			g->class->next->HP -= g->mob->ATK;
		else if (g->class->HP > 0)
			g->class->HP -= g->mob->ATK;
	}
}

void text_afterfight(p_game *g)
{
	g->status = 9;
	if (g->fight_mob == 3)
		wrapper(g, "scripts/S_06.sc", g->player_name);
	else if (g->fight_mob == 2)
		switch (g->actual_zone) {
		case 0:
			wrapper(g, "scripts/S_02.sc", g->player_name);
			break;
		case 1:
			wrapper(g, "scripts/S_03.sc", g->player_name);
			break;
		case 2:
			wrapper(g, "scripts/S_04.sc", g->player_name);
			break;
		case 3:
			wrapper(g, "scripts/S_05.sc", g->player_name);
			break;
		}
	else
		wrapper(g, "scripts/VICTORY_MSG.sc", g->player_name);
	g->status = 2;
}

void update_fight(p_game *g)
{
	sfVector2u pos = sfRenderWindow_getSize(g->window);
	sfVector2f center;
	int y = sfTime_asMilliseconds(sfClock_getElapsedTime(g->parts_clock));
	int y2 = g->i_player.pos.y / 64;
	int x = g->i_player.pos.x / 64;

	center.x = pos.x / 2;
	center.y = pos.y / 2;
	sfView_setCenter(g->view, center);
	sfRenderWindow_setView(g->window, g->view);
	draw_fight(g);
	if (g->mob->HP <= 0) {
		g->status = 2;
		g->xp += 3;
		if (g->xp >= 20) {
			g->xp -= 20;
			g->level++;
		}
		if (g->fight_mob == 2) {
			add_item(g, "sword", 0, rand() % 5 + 1);
			g->map[y2][x] = '3';
		}
		text_afterfight(g);
	}
	if (g->fight_turn == 0)
		update_player_1(g, y);
	else if (g->fight_turn == 1)
		update_player_2(g, y);
	else if (g->fight_turn == 2)
		update_player_3(g, y);
	else if (g->fight_turn == 3)
		update_player_4(g, y);
	else if (g->fight_turn == 4)
		update_mob(g, y);
}
