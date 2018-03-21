/*
** EPITECH PROJECT, 2018
** game_init
** File description:
** c file
*/

#include "my_rpg.h"

int game_init(p_game *g, int x, int y)
{
	char *name = "Isekai wa ore to kanojo o sukuu";
	sfVideoMode mode = {1600, 900, 32};

	create_title_screen(g);
	g->gold = 975314;
	g->music_ts = sfMusic_createFromFile("music/ts.ogg");
	g->s_map = sfSprite_create();
	g->t_map = sfTexture_createFromFile("image/map.png", NULL);
	if (!g->t_map)
		return (84);
	sfSprite_setTexture(g->s_map, g->t_map, sfTrue);
	g->rect_map.left = 0;
	g->rect_map.top = 0;
	g->rect_map.width = 32;
	g->rect_map.height = 32;
	g->player_direction = 0;
	g->player_move = 0;
	if (set_img_sprite(&g->i_player, "image/player.png") == 84)
		return (84);
	g->player_clock = sfClock_create();
	x = x * g->rect_map.width;
	y = y * g->rect_map.height;
	set_img_pos(&g->i_player, x, y);
	g->i_player.rect.width /= 4;
	g->i_player.rect.height /= 3;
	sfSprite_setTextureRect(g->i_player.sprite, g->i_player.rect);
	g->count_tx = 0;
	g->sprite_tx = sfSprite_create();
	sfSprite_setTexture(g->sprite_tx, g->title_scr[0], sfTrue);
	g->clock_tx = sfClock_create();
	g->window = sfRenderWindow_create(mode, name, sfClose, NULL);
	if (!g->window)
		return (84);
	sfRenderWindow_setFramerateLimit(g->window, 60);
	g->view = sfView_copy(sfRenderWindow_getView(g->window));
	sfRenderWindow_setView(g->window, g->view);
	g->status = 0;
	g->status_start_menu = 0;
	g->status_game_menu = 0;
	g->p_map.x = 0;
	g->p_map.y = 0;
	if (set_img_sprite(&g->i_nbr_gold, "image/misc/number.png") == 84)
		return (84);
	g->i_nbr_gold.rect.width /= 10;
	sfSprite_setTextureRect(g->i_nbr_gold.sprite, g->i_nbr_gold.rect);
	if (set_img_sprite(&g->i_start_menu, "image/ui/start_menu.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bg_menu, "image/ui/bg_menu.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_dark_screen, "image/ui/dark_screen.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_game_menu, "image/ui/game_menu.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_bt_start, "image/bt/bt_start.png") == 84)
		return (84);
	set_img_pos(&g->i_bt_start, 171, 144);
	set_img_rect_size(&g->i_bt_start, 260, 86);
	g->bt_start.clock = sfClock_create();
	g->bt_start.status = 0;
	if (set_img_sprite(&g->i_bt_load, "image/bt/bt_load.png") == 84)
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
	if (set_img_sprite(&g->i_bt_skills, "image/bt/bt_game_menu.png") == 84)
		return (84);
	g->i_bt_skills.rect.width /= 3;
	sfSprite_setTextureRect(g->i_bt_skills.sprite, g->i_bt_skills.rect);
	set_img_pos(&g->i_bt_skills, 334, 128);
	g->bt_skills.clock = sfClock_create();
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
	return (0);
}
