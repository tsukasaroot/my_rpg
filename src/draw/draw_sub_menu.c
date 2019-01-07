/*
** EPITECH PROJECT, 2018
** draw_sub_menu
** File description:
** c file
*/

#include "my_rpg.h"

void draw_status_player_part2(p_game *g, t_class_stat *c, int x)
{
	sfVector2f pos;

	draw_text(g, c->name, x - 170, 230);
	pos.x = x - 40;
	pos.y = 320;
	draw_nbr(g, &g->i_nbr_silver, c->HEALTH, pos);
	pos.y = 348;
	draw_nbr(g, &g->i_nbr_silver, c->MANA, pos);
	pos.x = x + 60;
	pos.y = 320;
	draw_nbr(g, &g->i_nbr_silver, c->HEALTH, pos);
	pos.y = 348;
	draw_nbr(g, &g->i_nbr_silver, c->MANA, pos);
	pos.x = x;
	pos.y = 635;
	draw_nbr(g, &g->i_nbr_silver, c->helmet, pos);
	pos.y = 670;
	draw_nbr(g, &g->i_nbr_silver, c->gloves, pos);
}

void draw_status_player(p_game *g, t_class_stat *c, int x)
{
	sfVector2f pos;

	pos.x = x;
	pos.y = 280;
	draw_nbr(g, &g->i_nbr_silver, g->level, pos);
	pos.y = 383;
	draw_nbr(g, &g->i_nbr_silver, g->xp, pos);
	pos.y = 410;
	draw_nbr(g, &g->i_nbr_silver, 20, pos);
	pos.y = 570;
	draw_nbr(g, &g->i_nbr_silver, c->weapon_pow, pos);
	pos.y = 605;
	draw_nbr(g, &g->i_nbr_silver, c->chestplate, pos);
	pos.y = 440;
	draw_nbr(g, &g->i_nbr_silver, c->ATK, pos);
	pos.x = x + 160;
	draw_nbr(g, &g->i_nbr_silver, c->DEF, pos);
	pos.y = 470;
	draw_nbr(g, &g->i_nbr_silver, c->SPEED, pos);
	draw_status_player_part2(g, c, x);
}

void draw_menu_status(p_game *g)
{
	if (my_strcmp("\"Slayer\"", g->select_perso->name)) {
		set_img_pos(&g->i_face_1, 822, 122);
		set_img_relative_pos(g, &g->i_face_1);
		draw_sprite(g, g->i_face_1.sprite);
	} else if (my_strcmp("\"Knight\"", g->select_perso->name)) {
		set_img_pos(&g->i_face_2, 822, 122);
		set_img_relative_pos(g, &g->i_face_2);
		draw_sprite(g, g->i_face_2.sprite);
	} else if (my_strcmp("\"Priest\"", g->select_perso->name)) {
		set_img_pos(&g->i_face_4, 818, 122);
		set_img_relative_pos(g, &g->i_face_4);
		draw_sprite(g, g->i_face_4.sprite);
	} else {
		set_img_pos(&g->i_face_3, 822, 122);
		set_img_relative_pos(g, &g->i_face_3);
		draw_sprite(g, g->i_face_3.sprite);
	}
	set_img_center(g, &g->i_menu_status);
	sfRenderWindow_drawSprite(g->window, g->i_menu_status.sprite, NULL);
	draw_status_player(g, g->select_perso, 560);
}

void draw_menu_story(p_game *g)
{
	set_img_center(g, &g->i_menu_story);
	sfRenderWindow_drawSprite(g->window, g->i_menu_story.sprite, NULL);
}

void draw_menu_save(p_game *g)
{
	set_img_center(g, &g->i_menu_save);
	sfRenderWindow_drawSprite(g->window, g->i_menu_save.sprite, NULL);
}
