/*
** EPITECH PROJECT, 2018
** draw start menu option
** File description:
** c file
*/

#include "my_rpg.h"

void draw_start_menu_option(p_game *g)
{
	sfVector2f pos;

	pos.x = 1440;
	pos.y = 100;
	set_img_relative_pos(g, &g->i_bg_menu);
	sfRenderWindow_drawSprite(g->window, g->i_bg_menu.sprite, NULL);
	draw_text(g, "Volume :", 800, 100);
	draw_text(g, "Change key", 800, 130);
	draw_text(g, "Press ESCAPE to quit menu", 650, 800);
	set_img_pos(&g->i_bt_music_l, 1320, 100);
	set_img_relative_pos(g, &g->i_bt_music_l);
	sfRenderWindow_drawSprite(g->window, g->i_bt_music_l.sprite, NULL);
	draw_nbr(g, &g->i_nbr_silver, g->music_volume, pos);
	set_img_pos(&g->i_bt_music_r, 1450, 100);
	set_img_relative_pos(g, &g->i_bt_music_r);
	sfRenderWindow_drawSprite(g->window, g->i_bt_music_r.sprite, NULL);
	set_img_pos(&g->i_cursor, 700, 100 + ((g->option_select - 1) * 30));
	set_img_relative_pos(g, &g->i_cursor);
	sfRenderWindow_drawSprite(g->window, g->i_cursor.sprite, NULL);
}
