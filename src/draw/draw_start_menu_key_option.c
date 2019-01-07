/*
** EPITECH PROJECT, 2018
** draw start menu key option
** File description:
** c file
*/

#include "my_rpg.h"

void draw_start_menu_key_option_part2(p_game *g)
{
	if (g->change_key == 1) {
		set_img_center(g, &g->i_dark_screen);
		draw_sprite(g, g->i_dark_screen.sprite);
	}
}

void draw_start_menu_key_option(p_game *g)
{
	set_img_relative_pos(g, &g->i_bg_menu);
	sfRenderWindow_drawSprite(g->window, g->i_bg_menu.sprite, NULL);
	draw_text(g, "Key UP :", 800, 100);
	draw_text_key(g, g->key_move_up, 1300, 100);
	draw_text(g, "Key DOWN :", 800, 130);
	draw_text_key(g, g->key_move_down, 1300, 130);
	draw_text(g, "Key LEFT :", 800, 160);
	draw_text_key(g, g->key_move_left, 1300, 160);
	draw_text(g, "Key RIGHT :", 800, 190);
	draw_text_key(g, g->key_move_right, 1300, 190);
	draw_text(g, "Inventory :", 800, 220);
	draw_text_key(g, g->key_inventory, 1300, 220);
	draw_text(g, "Press ESCAPE to quit menu", 650, 800);
	set_img_pos(&g->i_cursor, 700, 100 + ((g->option_select - 1) * 30));
	set_img_relative_pos(g, &g->i_cursor);
	sfRenderWindow_drawSprite(g->window, g->i_cursor.sprite, NULL);
	draw_start_menu_key_option_part2(g);
}
