/*
** EPITECH PROJECT, 2018
** key menu
** File description:
** c file
*/

#include "my_rpg.h"

void key_equip_menu(p_game *g, sfEvent *event)
{
	if (event->key.code == sfKeyRight) {
		if (g->select_perso->next != NULL)
			g->select_perso = g->select_perso->next;
		else
			g->select_perso = g->class;
		return;
	}
	if (event->key.code != sfKeyLeft)
		return;
	if (g->select_perso->next == NULL) {
		g->select_perso = g->class->next->next;
	} else if (g->select_perso->next->next == NULL) {
		g->select_perso = g->class->next;
	} else if (g->select_perso->next->next->next == NULL) {
		g->select_perso = g->class;
	} else if (g->select_perso->next->next->next->next == NULL) {
		g->select_perso = g->class->next->next->next;
	}
}

void key_menu(p_game *g, sfEvent *event)
{
	int status = g->status_game_menu;

	if (g->status_start_menu != 3 && event->key.code == sfKeyEscape) {
		if (g->status_game_menu == 0) {
			reset_status(g);
			g->status = 2;
		} else
			g->status_game_menu = 0;
	} else if (status == 1 && event->key.code == g->key_inventory) {
		reset_status(g);
		g->status = 2;
	} else if (status == 3 || status == 4) {
		key_equip_menu(g, event);
	} else if (status == 6) {
		if (g->status_start_menu == 2)
			key_start_menu_option(g, event);
		else if (g->status_start_menu == 3)
			key_start_menu_option_key(g, event);
	}
}
