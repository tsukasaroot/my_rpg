/*
** EPITECH PROJECT, 2018
** set text key
** File description:
** c file
*/

#include "my_rpg.h"

void draw_text_key(p_game *g, int key, int x, int y)
{
	char *text = find_key(key);

	if (text != NULL) {
		sfText_setString(g->text, text);
		set_text_pos(g, x, y);
		sfRenderWindow_drawText(g->window, g->text, NULL);
		free(text);
	}
}
