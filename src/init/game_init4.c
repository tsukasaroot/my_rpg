/*
** EPITECH PROJECT, 2018
** game_init
** File description:
** c file
*/

#include "my_rpg.h"

int init11(p_game *g)
{
	g->bt_skills.status = 0;
	if (set_img_sprite(&g->i_menu_skill, "image/ui/skill.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_equip, "image/bt/bt_game_menu.png") == 84)
		return (84);
	g->i_bt_equip.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_equip.sprite, g->i_bt_equip.rect);
	set_img_pos(&g->i_bt_equip, 490, 128);
	g->bt_equip.clock = sfClock_create();
	g->bt_equip.status = 0;
	if (set_img_sprite(&g->i_menu_equip, "image/ui/equip.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_status, "image/bt/bt_game_menu.png") == 84)
		return (84);
	g->i_bt_status.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_status.sprite, g->i_bt_status.rect);
	set_img_pos(&g->i_bt_status, 650, 128);
	g->bt_status.clock = sfClock_create();
	g->bt_status.status = 0;
	return (0);
}

int init12(p_game *g)
{
	if (set_img_sprite(&g->i_menu_status, "image/ui/status.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_story, "image/bt/bt_game_menu.png") == 84)
		return (84);
	g->i_bt_story.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_story.sprite, g->i_bt_story.rect);
	set_img_pos(&g->i_bt_story, 800, 128);
	g->bt_story.clock = sfClock_create();
	g->bt_story.status = 0;
	if (set_img_sprite(&g->i_menu_story, "image/ui/story.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_setup, "image/bt/bt_game_menu.png") == 84)
		return (84);
	g->i_bt_setup.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_setup.sprite, g->i_bt_setup.rect);
	set_img_pos(&g->i_bt_setup, 960, 128);
	g->bt_setup.clock = sfClock_create();
	g->bt_setup.status = 0;
	return (0);
}

int init13(p_game *g)
{
	if (set_img_sprite(&g->i_menu_setup, "image/ui/bg_menu.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_save, "image/bt/bt_game_menu.png") == 84)
		return (84);
	g->i_bt_save.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_save.sprite, g->i_bt_save.rect);
	set_img_pos(&g->i_bt_save, 1125, 128);
	g->bt_save.clock = sfClock_create();
	g->bt_save.status = 0;
	if (set_img_sprite(&g->i_menu_save, "image/ui/save.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_end, "image/bt/bt_game_menu.png") == 84)
		return (84);
	g->i_bt_end.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_end.sprite, g->i_bt_end.rect);
	set_img_pos(&g->i_bt_end, 1270, 128);
	g->bt_end.clock = sfClock_create();
	g->bt_end.status = 0;
	return (0);
}

int init14(p_game *g)
{
	if (set_img_sprite(&g->i_bt_skills, "image/bt/bt_game_menu.png") == 84)
		return (84);
	g->i_bt_skills.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_skills.sprite, g->i_bt_skills.rect);
	set_img_pos(&g->i_bt_skills, 334, 128);
	g->bt_skills.clock = sfClock_create();
	g->bt_skills.status = 0;
	if (set_img_sprite(&g->i_bt_quit_m, "image/bt/bt_quit_menu.png") == 84)
		return (84);
	g->i_bt_quit_m.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_quit_m.sprite, g->i_bt_quit_m.rect);
	set_img_pos(&g->i_bt_quit_m, 1400, 90);
	g->bt_quit_m.clock = sfClock_create();
	g->bt_quit_m.status = 0;
	if (set_img_sprite(&g->i_skill_choice, "image/ui/skill_c.png") == 84)
		return (84);
	return (0);
}

int init15(p_game *g)
{
	if (set_img_sprite(&g->i_mob1, "image/mobs/mob1.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_mob2, "image/boss/boss2.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_mob3, "image/boss/boss.png") == 84)
		return (84);
	g->title_clock = sfClock_create();
	if (set_img_sprite(&g->i_parts, "image/parts.png") == 84)
		return (84);
	g->parts_clock = sfClock_create();
	g->parts = NULL;
	g->last_parts = 0;
	g->title_text = NULL;
	g->select_perso = g->class;
	g->music_fight = sfMusic_createFromFile("music/b4.ogg");
	if (!g->music_fight)
		return (84);
	sfMusic_setVolume(g->music_fight, g->music_volume);
	sfMusic_setLoop(g->music_fight, 1);
	return (0);
}
