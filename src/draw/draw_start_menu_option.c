/*
** EPITECH PROJECT, 2018
** draw start menu option
** File description:
** c file
*/

#include "my_rpg.h"

void draw_start_menu_option(p_game *g)
{
	sfRenderWindow_drawSprite(g->window, g->i_bg_menu.sprite, NULL);
}
