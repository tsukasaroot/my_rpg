/*
** EPITECH PROJECT, 2018
** reset status
** File description:
** c file
*/

#include "my_rpg.h"

void reset_status(p_game *g)
{
	g->status_start_menu = 0;
	g->status_game_menu = 0;
	g->option_select = 1;
	g->bt_load.status = 0;
	g->bt_option.status = 0;
	g->bt_quit.status = 0;
	g->bt_start.status = 0;
	g->bt_item.status = 0;
	g->bt_skills.status = 0;
	g->bt_equip.status = 0;
	g->bt_status.status = 0;
	g->bt_story.status = 0;
	g->bt_setup.status = 0;
	g->bt_save.status = 0;
	g->bt_end.status = 0;
	g->bt_quit.status = 0;
}
