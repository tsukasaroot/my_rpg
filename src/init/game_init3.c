/*
** EPITECH PROJECT, 2018
** game init
** File description:
** c file
*/

#include "my_rpg.h"

int init6(p_game *g)
{
	g->status = 0;
	g->status_intro = 1;
	g->status_start_menu = 0;
	g->status_game_menu = 0;
	g->option_select = 1;
	g->change_key = 0;
	g->p_map.x = 0;
	g->p_map.y = 0;
	if (set_img_sprite(&g->i_dialogue, "image/ui/dialogue.png") == 84)
		return (84);
	set_img_pos(&g->i_dialogue, 407, 550);
	if (set_img_sprite(&g->i_nbr_gold, "image/misc/number.png") == 84)
		return (84);
	g->i_nbr_gold.rect.width /= 10;
	if (set_img_sprite(&g->i_nbr_silver, "image/misc/number_2.png") == 84)
		return (84);
	g->i_nbr_silver.rect.width /= 10;
	sfSprite_setTextureRect(g->i_nbr_gold.sprite, g->i_nbr_gold.rect);
	g->i_bt_ch_itm.rect.width /= 3;
	return (0);
}

int init7(p_game *g)
{
	if (set_img_sprite(&g->i_start_menu, "image/ui/start_menu.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bg_menu, "image/ui/bg_menu.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_dark_screen,
			"image/ui/dark_screen.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_game_menu, "image/ui/game_menu2.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bg_fight1, "image/fight_bg/cave.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_start, "image/bt/bt_start.png") == 84)
		return (84);
	set_img_pos(&g->i_bt_start, 171, 144);
	set_img_rect_size(&g->i_bt_start, 260, 86);
	g->bt_start.clock = sfClock_create();
	g->bt_start.status = 0;
	if (set_img_sprite(&g->i_bt_ch_itm, "image/bt/bt_game_menu.png") == 84)
		return (84);
	return (0);
}

int init8(p_game *g)
{
	if (set_img_sprite(&g->i_bt_plus, "image/bt/bt_plus.png") == 84)
		return (84);
	g->i_bt_plus.rect.width /= 3;
	g->bt_plus.clock = sfClock_create();
	g->bt_plus.status = 0;
	set_img_pos(&g->i_bt_ch_itm, 900, 500);
	set_img_rect_size(&g->i_bt_ch_itm, 260, 86);
	g->bt_ch_itm.clock = sfClock_create();
	g->bt_ch_itm.status = 0;
	if (set_img_sprite(&g->i_cursor, "image/ui/right.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_music_l, "image/ui/left.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_music_r, "image/ui/right.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_load, "image/bt/bt_load.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_face_1, "image/char/warrior/f_1.png") == 84)
		return (84);
	return (0);
}

int init9(p_game *g)
{
	if (set_img_sprite(&g->i_face_2, "image/char/knight/f_1.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_face_3, "image/char/magician/f_1.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_face_4, "image/char/healer/f_1.png") == 84)
		return (84);
	set_img_pos(&g->i_bt_load, 180, 283);
	set_img_rect_size(&g->i_bt_load, 237, 77);
	g->bt_load.clock = sfClock_create();
	g->bt_load.status = 0;
	if (set_img_sprite(&g->i_bt_option, "image/bt/bt_option.png") == 84)
		return (84);
	set_img_pos(&g->i_bt_option, 173, 415);
	set_img_rect_size(&g->i_bt_option, 253, 73);
	g->bt_option.clock = sfClock_create();
	g->bt_option.status = 0;
	if (set_img_sprite(&g->i_bt_quit, "image/bt/bt_quit.png") == 84)
		return (84);
	set_img_pos(&g->i_bt_quit, 176, 547);
	return (0);
}

int init10(p_game *g)
{
	set_img_rect_size(&g->i_bt_quit, 249, 78);
	g->bt_quit.clock = sfClock_create();
	g->bt_quit.status = 0;
	if (set_img_sprite(&g->i_bt_item, "image/bt/bt_game_menu.png") == 84)
		return (84);
	g->i_bt_item.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_item.sprite, g->i_bt_item.rect);
	set_img_pos(&g->i_bt_item, 176, 128);
	g->bt_item.clock = sfClock_create();
	g->bt_item.status = 0;
	if (set_img_sprite(&g->i_menu_item, "image/ui/inventory.png") == 84)
		return (84);
	g->inventory = NULL;
	if (set_img_sprite(&g->i_bt_skills, "image/bt/bt_game_menu.png") == 84)
		return (84);
	g->i_bt_skills.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_skills.sprite, g->i_bt_skills.rect);
	set_img_pos(&g->i_bt_skills, 334, 128);
	g->bt_skills.clock = sfClock_create();
	return (0);
}
