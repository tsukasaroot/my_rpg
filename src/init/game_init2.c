/*
** EPITECH PROJECT, 2018
** game_init
** File description:
** c file
*/

#include "my_rpg.h"

void init1(p_game *g)
{
	g->level = 1;
	g->xp = 0;
	g->skill_select = 0;
	create_title_screen(g);
	create_transition_battle(g);
	g->itm_select = NULL;
	g->player_name = NULL;
	g->key_press_move_up = 0;
	g->key_press_move_down = 0;
	g->key_press_move_left = 0;
	g->key_press_move_right = 0;
	g->gold = 0;
	g->zone = 0;
	g->actual_zone = g->zone;
	g->boss_zone = 0;
	g->key_inventory = sfKeyI;
	g->key_move_left = sfKeyLeft;
	g->key_move_right = sfKeyRight;
	g->key_move_up = sfKeyUp;
	g->key_move_down = sfKeyDown;
}

int init2(p_game *g)
{
	if (get_items(g) == 84)
		return (84);
	g->font = sfFont_createFromFile("image/misc/Freshman.ttf");
	if (!g->font)
		return (84);
	g->text = sfText_create();
	sfText_setCharacterSize(g->text, 26);
	sfText_setFont(g->text, g->font);
	g->music_volume = 100;
	g->music_ts = sfMusic_createFromFile("music/ts.ogg");
	if (!g->music_ts)
		return (84);
	sfMusic_setVolume(g->music_ts, g->music_volume);
	sfMusic_setLoop(g->music_ts, 1);
	sfMusic_play(g->music_ts);
	g->music_land = sfMusic_createFromFile("music/land.ogg");
	if (!g->music_land)
		return (84);
	return (0);
}

int init3(p_game *g)
{
	sfMusic_setVolume(g->music_land, g->music_volume);
	sfMusic_setLoop(g->music_land, 1);
	g->music_button = sfMusic_createFromFile("music/button.ogg");
	if (!g->music_button)
		return (84);
	sfMusic_setVolume(g->music_button, 100);
	g->s_map = sfSprite_create();
	g->t_map = sfTexture_createFromFile("image/map.jpg", NULL);
	if (!g->t_map)
		return (84);
	sfSprite_setTexture(g->s_map, g->t_map, sfTrue);
	g->s_boss_map = sfSprite_create();
	g->t_boss_map = sfTexture_createFromFile("image/boss_map.png", NULL);
	if (!g->t_boss_map)
		return (84);
	sfSprite_setTexture(g->s_boss_map, g->t_boss_map, sfTrue);
	g->s_f_boss_map = sfSprite_create();
	g->t_f_boss_map = sfTexture_createFromFile("image/fboss_map.png",
						NULL);
	return (0);
}

int init4(p_game *g)
{
	if (!g->t_f_boss_map)
		return (84);
	sfSprite_setTexture(g->s_f_boss_map, g->t_f_boss_map, sfTrue);
	g->rect_map.left = 0;
	g->rect_map.top = 0;
	g->rect_map.width = 64;
	g->rect_map.height = 64;
	g->player_direction = 0;
	g->player_move = 0;
	if (set_img_sprite(&g->i_items, "image/ui/stuff.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_pseudo, "image/ui/pseudo.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_player, "image/playerx64.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_pnj[0], "image/NPC/NPC_8.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_pnj[1], "image/NPC/mob1.png") == 84)
		return (84);
	return (0);
}

int init5(p_game *g, char *name, sfVideoMode mode)
{
	if (set_img_sprite(&g->i_pnj[2], "image/NPC/mob2.png") == 84)
		return (84);
	if (set_img_sprite(&g->i_pnj[3], "image/NPC/mob3.png") == 84)
		return (84);
	g->player_clock = sfClock_create();
	g->playera_clock = sfClock_create();
	g->i_player.rect.width /= 4;
	g->i_player.rect.height /= 4;
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
	return (0);
}
