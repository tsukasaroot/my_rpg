/*
** EPITECH PROJECT, 2018
** draw_sub_menu
** File description:
** c file
*/

#include "my_rpg.h"

void draw_menu_item(p_game *g)
{
	set_img_center(g, &g->i_menu_item);
	sfRenderWindow_drawSprite(g->window, g->i_menu_item.sprite, NULL);
}

void draw_menu_equip(p_game *g)
{
	set_img_center(g, &g->i_menu_equip);
	sfRenderWindow_drawSprite(g->window, g->i_menu_equip.sprite, NULL);
}

void draw_menu_status(p_game *g)
{
	set_img_center(g, &g->i_menu_status);
	sfRenderWindow_drawSprite(g->window, g->i_menu_status.sprite, NULL);
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
