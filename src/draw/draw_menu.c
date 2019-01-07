/*
** EPITECH PROJECT, 2018
** draw menu
** File description:
** c file
*/

#include "my_rpg.h"

void draw_faceset(p_game *g)
{
	draw_stat_player(g, g->class, 340);
	set_img_pos(&g->i_face_1, 375, 240);
	set_img_relative_pos(g, &g->i_face_1);
	draw_sprite(g, g->i_face_1.sprite);
	set_img_pos(&g->i_face_2, 690, 240);
	set_img_relative_pos(g, &g->i_face_2);
	draw_sprite(g, g->i_face_2.sprite);
	set_img_pos(&g->i_face_3, 1005, 241);
	set_img_relative_pos(g, &g->i_face_3);
	draw_sprite(g, g->i_face_3.sprite);
	set_img_pos(&g->i_face_4, 1323, 239);
	set_img_relative_pos(g, &g->i_face_4);
	draw_sprite(g, g->i_face_4.sprite);
}

void draw_stat_player_part2(p_game *g, t_class_stat *c, int x)
{
	sfVector2f pos;

	draw_text(g, c->name, x - 120, 245);
	pos.x = x - 40;
	pos.y = 327;
	draw_nbr(g, &g->i_nbr_silver, c->HEALTH, pos);
	pos.y = 355;
	draw_nbr(g, &g->i_nbr_silver, c->MANA, pos);
	pos.x = x + 40;
	pos.y = 327;
	draw_nbr(g, &g->i_nbr_silver, c->HEALTH, pos);
	pos.y = 355;
	draw_nbr(g, &g->i_nbr_silver, c->MANA, pos);
	pos.x = x;
	pos.y = 610;
	draw_nbr(g, &g->i_nbr_silver, c->helmet, pos);
	pos.y = 640;
	draw_nbr(g, &g->i_nbr_silver, c->gloves, pos);
	if (c->next != NULL)
		draw_stat_player(g, c->next, x + 315);
}

void draw_stat_player(p_game *g, t_class_stat *c, int x)
{
	sfVector2f pos;

	pos.x = x;
	pos.y = 300;
	draw_nbr(g, &g->i_nbr_silver, g->level, pos);
	pos.y = 383;
	draw_nbr(g, &g->i_nbr_silver, g->xp, pos);
	pos.y = 410;
	draw_nbr(g, &g->i_nbr_silver, 20, pos);
	pos.y = 550;
	draw_nbr(g, &g->i_nbr_silver, c->weapon_pow, pos);
	pos.y = 580;
	draw_nbr(g, &g->i_nbr_silver, c->chestplate, pos);
	pos.y = 437;
	draw_nbr(g, &g->i_nbr_silver, c->ATK, pos);
	pos.x = x + 120;
	draw_nbr(g, &g->i_nbr_silver, c->DEF, pos);
	pos.y = 465;
	draw_nbr(g, &g->i_nbr_silver, c->SPEED, pos);
	draw_stat_player_part2(g, c, x);
}

void draw_menu_part2(p_game *g)
{
	sfVector2f pos;

	set_img_relative_pos(g, &g->i_bt_end);
	draw_button(g, &g->bt_end, &g->i_bt_end);
	set_img_relative_pos(g, &g->i_bt_quit_m);
	draw_button(g, &g->bt_quit_m, &g->i_bt_quit_m);
	pos.x = 1380;
	pos.y = 757;
	draw_zone(g);
	draw_nbr(g, &g->i_nbr_gold, g->gold, pos);
	draw_faceset(g);
}

void draw_menu(p_game *g)
{
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
	draw_menu_part2(g);
}
