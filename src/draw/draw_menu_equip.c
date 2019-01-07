/*
** EPITECH PROJECT, 2018
** draw menu equip
** File description:
** c file
*/

#include "my_rpg.h"

void draw_item_equip(p_game *g, sfVector2f pos)
{
	if (g->itm_select->id == 5) {
		draw_text(g, "gloves :", 800, 450);
		draw_nbr(g, &g->i_nbr_silver, g->select_perso->gloves, pos);
	} else if (g->itm_select->id == 4) {
		draw_text(g, "helmet :", 800, 450);
		draw_nbr(g, &g->i_nbr_silver, g->select_perso->helmet, pos);
	} else if (g->itm_select->id == 3) {
		draw_text(g, "chestplate :", 800, 450);
		draw_nbr(g, &g->i_nbr_silver, g->select_perso->chestplate, pos);
	} else if (g->itm_select->id == 2 && g->select_perso->weapon_id == 2) {
		draw_text(g, "Staff :", 800, 450);
		draw_nbr(g, &g->i_nbr_silver, g->select_perso->weapon_pow, pos);
	} else if (g->itm_select->id == 0 && g->select_perso->weapon_id == 0) {
		draw_text(g, "Sword :", 800, 450);
		draw_nbr(g, &g->i_nbr_silver, g->select_perso->weapon_pow, pos);
	} else if (g->itm_select->id == 1 && g->select_perso->shield != 0) {
		draw_text(g, "shield :", 800, 450);
		draw_nbr(g, &g->i_nbr_silver, g->select_perso->shield, pos);
	} else
		draw_text(g, "invalid class", 800, 450);
}

void draw_item_select(p_game *g)
{
	sfVector2f pos;

	if (g->itm_select != NULL) {
		draw_text(g, g->itm_select->name, 800, 310);
		draw_text(g, "power :", 800, 340);
		pos.x = 1000;
		pos.y = 342;
		draw_nbr(g, &g->i_nbr_silver, g->itm_select->power, pos);
		pos.x = 1000;
		pos.y = 452;
		draw_item_equip(g, pos);
		set_img_relative_pos(g, &g->i_bt_ch_itm);
		if (g->itm_select != NULL &&
		(g->itm_select->id > 2 ||
		g->itm_select->id == g->select_perso->weapon_id ||
		(g->itm_select->id == 1 &&
		g->select_perso->shield != 0)))
			draw_text(g, "change item", 950, 550);
	}
}

void draw_menu_equip(p_game *g)
{
	sfVector2f pos;
	set_img_center(g, &g->i_menu_equip);
	sfRenderWindow_drawSprite(g->window, g->i_menu_equip.sprite, NULL);
	draw_text(g, "Equip", 750, 175);
	draw_text(g, g->select_perso->name, 800, 250);
	draw_text(g, "item select :", 800, 280);
	draw_text(g, "item equip :", 800, 390);
	draw_item_select(g);
	pos.x = g->i_player.pos.x - 420;
	pos.y = g->i_player.pos.y - 190;
	draw_item(g, g->inventory, pos, 1);
	draw_text(g, "use KEY RIGHT to select next player", 650, 700);
}
