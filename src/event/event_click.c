/*
** EPITECH PROJECT, 2018
** event click
** File description:
** event file
*/

#include "my_rpg.h"

void check_click_inventory_item(p_game *g, p_item *itm, int x, int y)
{
	if (itm == NULL)
		return;
	if (x >= itm->pos.x && x <= itm->pos.x + 50 &&
		y >= itm->pos.y && y <= itm->pos.y + 50) {
			g->itm_select = itm;
	} else
		check_click_inventory_item(g, itm->next, x, y);
}

void check_click_inventory(p_game *g, sfEvent *event)
{
	int x = event->mouseButton.x + g->i_player.pos.x - 800;
	int y = event->mouseButton.y + g->i_player.pos.y - 450;

	check_click_inventory_item(g, g->inventory, x, y);
}

void check_click_equip(p_game *g, sfEvent *event)
{
	int x = event->mouseButton.x + g->i_player.pos.x - 800;
	int y = event->mouseButton.y + g->i_player.pos.y - 450;

	check_click_inventory_item(g, g->inventory, x, y);
}

void my_event_click(p_game *g, sfEvent *event)
{
	if (event->type != sfEvtMouseButtonPressed)
		return;
	if (g->status == 4) {
		if (g->status_game_menu == 1)
			check_click_inventory(g, event);
		else if (g->status_game_menu == 3)
			check_click_equip(g, event);
	}
}
