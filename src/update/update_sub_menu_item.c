/*
** EPITECH PROJECT, 2018
** update_menu
** File description:
** c file
*/

#include "my_rpg.h"

void update_menu_item(p_game *g)
{
	set_img_center(g, &g->i_dark_screen);
	sfRenderWindow_drawSprite(g->window, g->i_dark_screen.sprite, NULL);
	draw_menu_item(g);
}

void update_menu_equip(p_game *g)
{
	set_img_center(g, &g->i_dark_screen);
	sfRenderWindow_drawSprite(g->window, g->i_dark_screen.sprite, NULL);
	draw_menu_equip(g);
}

void update_menu_status(p_game *g)
{
	set_img_center(g, &g->i_dark_screen);
	sfRenderWindow_drawSprite(g->window, g->i_dark_screen.sprite, NULL);
	draw_menu_status(g);
}

void update_menu_story(p_game *g)
{
	set_img_center(g, &g->i_dark_screen);
	sfRenderWindow_drawSprite(g->window, g->i_dark_screen.sprite, NULL);
	draw_menu_story(g);
}

void update_menu_save(p_game *g)
{
	set_img_center(g, &g->i_dark_screen);
	sfRenderWindow_drawSprite(g->window, g->i_dark_screen.sprite, NULL);
	draw_menu_save(g);
}
