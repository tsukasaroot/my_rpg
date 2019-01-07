/*
** EPITECH PROJECT, 2018
** draw fight
** File description:
** c file
*/

#include "my_rpg.h"

void draw_fight_mob_nb(p_game *g, sfVector2f pos, int mob)
{
	int y = 0;

	switch (mob) {
		case 1:
			y = pos.y - g->i_mob1.rect.height;
			set_img_pos(&g->i_mob1, pos.x, y);
			draw_sprite(g, g->i_mob1.sprite);
			break;
		case 2:
			y = pos.y - g->i_mob2.rect.height;
			set_img_pos(&g->i_mob2, pos.x, y);
			draw_sprite(g, g->i_mob2.sprite);
			break;
		case 3:
			y = pos.y - g->i_mob3.rect.height;
			set_img_pos(&g->i_mob3, pos.x, y);
			draw_sprite(g, g->i_mob3.sprite);
			break;
	}
	pos.y += 30;
	draw_text(g, "HP", pos.x + 10, pos.y);
	draw_nbr(g, &g->i_nbr_silver, g->mob->HP, pos);
}

void draw_fight_char_nb(p_game *g, sfVector2f pos, int character)
{
	int y = 0;

	y = pos.y - g->i_char[character].rect.height;
	set_img_pos(&g->i_char[character], pos.x, y);
	draw_sprite(g, g->i_char[character].sprite);
}

void draw_fight_char(p_game *g)
{
	draw_fight_char_nb(g, g->p_char1, 0);
	draw_fight_char_nb(g, g->p_char2, 1);
	draw_fight_char_nb(g, g->p_char3, 2);
	draw_fight_char_nb(g, g->p_char4, 3);
}

void draw_fight_mob(p_game *g)
{
	int mob = 0;

	if (g->mob != NULL) {
		mob = g->fight_mob;
		if (g->p_char1.x > 750 && g->p_char2.x > 750 &&
			g->p_char3.x > 750 && g->p_char4.x > 750)
			draw_fight_mob_nb(g, g->p_mob1, mob);
	}
}

void draw_fight(p_game *g)
{
	sfVector2f pos;
	sfRenderWindow_drawSprite(g->window, g->i_bg_fight1.sprite, NULL);
	draw_fight_mob(g);
	draw_fight_char(g);
	pos.x = 1200;
	pos.y = 500;
	draw_text(g, "HP", pos.x + 10, pos.y);
	if (g->class->HP > 0)
		draw_nbr(g, &g->i_nbr_silver, g->class->HP, pos);
	else
		draw_nbr(g, &g->i_nbr_silver, 0, pos);
	pos.y = 600;
	draw_text(g, "HP", pos.x + 10, pos.y);
	if (g->class->next->HP > 0)
		draw_nbr(g, &g->i_nbr_silver, g->class->next->HP, pos);
	else
		draw_nbr(g, &g->i_nbr_silver, 0, pos);
	pos.y = 700;
	draw_text(g, "HP", pos.x + 10, pos.y);
	if (g->class->next->next->HP > 0)
		draw_nbr(g, &g->i_nbr_silver, g->class->next->next->HP, pos);
	else
		draw_nbr(g, &g->i_nbr_silver, 0, pos);
	pos.y = 800;
	draw_text(g, "HP", pos.x + 10, pos.y);
	if (g->class->next->next->next->HP > 0)
		draw_nbr(g, &g->i_nbr_silver, g->class->next->next->next->HP, pos);
	else
		draw_nbr(g, &g->i_nbr_silver, 0, pos);
}
