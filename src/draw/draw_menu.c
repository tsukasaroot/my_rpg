/*
** EPITECH PROJECT, 2018
** draw menu
** File description:
** c file
*/

#include "my_rpg.h"

void draw_menu(p_game *g)
{
	sfVector2f pos;

	set_img_center(g, &g->i_dark_screen);
	set_img_center(g, &g->i_game_menu);
	sfRenderWindow_drawSprite(g->window, g->i_dark_screen.sprite, NULL);
	sfRenderWindow_drawSprite(g->window, g->i_game_menu.sprite, NULL);
	set_img_relative_pos(g, &g->i_bt_item);
	draw_button(g, &g->bt_item, &g->i_bt_item);
	set_img_relative_pos(g, &g->i_bt_skills);
	draw_button(g, &g->bt_skills, &g->i_bt_skills);
	set_img_relative_pos(g, &g->i_bt_equip);
	draw_button(g, &g->bt_equip, &g->i_bt_equip);
	set_img_relative_pos(g, &g->i_bt_status);
	draw_button(g, &g->bt_status, &g->i_bt_status);
	set_img_relative_pos(g, &g->i_bt_story);
	draw_button(g, &g->bt_story, &g->i_bt_story);
	set_img_relative_pos(g, &g->i_bt_setup);
	draw_button(g, &g->bt_setup, &g->i_bt_setup);
	set_img_relative_pos(g, &g->i_bt_save);
	draw_button(g, &g->bt_save, &g->i_bt_save);
	set_img_relative_pos(g, &g->i_bt_end);
	draw_button(g, &g->bt_end, &g->i_bt_end);
	set_img_relative_pos(g, &g->i_bt_quit_m);
	draw_button(g, &g->bt_quit_m, &g->i_bt_quit_m);
	pos.x = 1380;
	pos.y = 757;
	draw_nbr(g, &g->i_nbr_gold, g->gold, pos);
}
