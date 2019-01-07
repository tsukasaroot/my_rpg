/*
** EPITECH PROJECT, 2018
** draw_sub_menu
** File description:
** c file
*/

#include "my_rpg.h"

void draw_menu_skill_select_name(p_game *g)
{
	switch (g->skill_select) {
		case 1:
			draw_text(g, "ATK", 800, 300);
			break;
		case 2:
			draw_text(g, "CRIT", 800, 300);
			break;
		case 3:
			draw_text(g, "DEF", 800, 300);
			break;
		case 4:
			draw_text(g, "HEALTH", 800, 300);
			break;
		case 5:
			draw_text(g, "MANA", 800, 300);
			break;
		case 6:
			draw_text(g, "SPD", 800, 300);
			break;
	}
}

void draw_menu_skill_select(p_game *g)
{
	sfVector2f pos;
	int ss = g->skill_select;

	pos.x = 980;
	pos.y = 300;
	draw_menu_skill_select_name(g);
	set_img_pos(&g->i_bt_plus, 700, 285);
	set_img_relative_pos(g, &g->i_bt_plus);
	draw_button(g, &g->bt_plus, &g->i_bt_plus);
	draw_nbr(g, &g->i_nbr_silver, g->spells[0].ATK_MOD[ss] * 10, pos);
	draw_text(g, "pourcent", 1000, 300);

}

void draw_menu_skill_part2(p_game *g, sfVector2f pos)
{
	pos.x = 600;
	pos.y = 300;
	draw_text(g, "ATK", 400, 300);
	draw_nbr(g, &g->i_nbr_silver, g->spells[0].ATK_MOD[1], pos);
	pos.y = 350;
	draw_text(g, "CRIT", 400, 350);
	draw_nbr(g, &g->i_nbr_silver, g->spells[0].ATK_MOD[2], pos);
	pos.y = 400;
	draw_text(g, "DEF", 400, 400);
	draw_nbr(g, &g->i_nbr_silver, g->spells[0].ATK_MOD[3], pos);
	pos.y = 450;
	draw_text(g, "HEALTH", 400, 450);
	draw_nbr(g, &g->i_nbr_silver, g->spells[0].ATK_MOD[4], pos);
	pos.y = 500;
	draw_text(g, "MANA", 400, 500);
	draw_nbr(g, &g->i_nbr_silver, g->spells[0].ATK_MOD[5], pos);
	pos.y = 550;
	draw_text(g, "SPD", 400, 550);
	draw_nbr(g, &g->i_nbr_silver, g->spells[0].ATK_MOD[6], pos);
}

void draw_menu_skill(p_game *g)
{
	sfVector2f pos;

	set_img_center(g, &g->i_menu_skill);
	sfRenderWindow_drawSprite(g->window, g->i_menu_skill.sprite, NULL);
	draw_text(g, "Skills", 750, 100);
	draw_text(g, g->select_perso->name, 400, 200);
	draw_menu_skill_part2(g, pos);
	draw_text(g, "You have", 820, 700);
	pos.x = 1040;
	pos.y = 700;
	draw_nbr(g, &g->i_nbr_silver, g->level - count_skills(g) - 1, pos);
	draw_text(g, "skills points", 1050, 700);
	if (g->skill_select > 0)
		draw_menu_skill_select(g);
}

void draw_menu_setup(p_game *g)
{
	set_img_center(g, &g->i_menu_setup);
	sfRenderWindow_drawSprite(g->window, g->i_menu_setup.sprite, NULL);
}
