/*
** EPITECH PROJECT, 2018
** draw_sub_menu
** File description:
** c file
*/

#include "my_rpg.h"

void draw_menu_skill(p_game *g)
{
	set_img_center(g, &g->i_menu_skill);
	sfRenderWindow_drawSprite(g->window, g->i_menu_skill.sprite, NULL);
}

void draw_menu_setup(p_game *g)
{
	set_img_center(g, &g->i_menu_setup);
	sfRenderWindow_drawSprite(g->window, g->i_menu_setup.sprite, NULL);
}
