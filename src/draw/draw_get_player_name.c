/*
** EPITECH PROJECT, 2018
** draw get player name
** File description:
** c file
*/

#include "my_rpg.h"

void draw_get_player_name(p_game *g)
{
	set_img_center(g, &g->i_pseudo);
	draw_sprite(g, g->i_pseudo.sprite);
	draw_text(g, "Choose player name :", 380, 350);
	draw_text(g, g->player_name, 670, 430);
}
