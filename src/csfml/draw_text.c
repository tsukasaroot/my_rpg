/*
** EPITECH PROJECT, 2018
** draw text
** File description:
** c file
*/

#include "my_rpg.h"

void draw_text(p_game *g, char *text, int x, int y)
{
	sfText_setString(g->text, text);
	set_text_pos(g, x, y);
	sfRenderWindow_drawText(g->window, g->text, NULL);
}
