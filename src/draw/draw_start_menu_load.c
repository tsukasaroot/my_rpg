/*
** EPITECH PROJECT, 2018
** draw start menu load
** File description:
** c file
*/

#include "my_rpg.h"

void draw_start_menu_load(p_game *g)
{
	set_img_relative_pos(g, &g->i_bg_menu);
	sfRenderWindow_drawSprite(g->window, g->i_bg_menu.sprite, NULL);
	draw_text(g, "Press ESCAPE to quit menu", 650, 800);
}
