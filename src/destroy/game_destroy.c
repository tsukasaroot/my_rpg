/*
** EPITECH PROJECT, 2018
** game_destroy
** File description:
** c file
*/

#include "my_rpg.h"

void game_destroy(p_game *g)
{
	sfTexture_destroy(g->t_map);
	sfSprite_destroy(g->s_map);
	free_img(&g->i_start_menu);
	free_img(&g->i_dark_screen);
	free_img(&g->i_game_menu);
	free_img(&g->i_bt_start);
	free_img(&g->i_bt_quit);
	free_img(&g->i_bt_load);
	free_img(&g->i_bt_option);
	free_img(&g->i_bt_item);
	free_img(&g->i_bt_skills);
	free_img(&g->i_bt_equip);
	free_img(&g->i_bt_status);
	free_img(&g->i_bt_story);
	free_img(&g->i_bt_setup);
	free_img(&g->i_bt_save);
	free_img(&g->i_bt_end);
	free_img(&g->i_bt_quit_m);
	sfClock_destroy(g->bt_start.clock);
	sfClock_destroy(g->bt_quit.clock);
	sfClock_destroy(g->bt_load.clock);
	sfClock_destroy(g->bt_option.clock);
	sfClock_destroy(g->bt_item.clock);
	sfClock_destroy(g->bt_skills.clock);
	sfClock_destroy(g->bt_equip.clock);
	sfClock_destroy(g->bt_status.clock);
	sfClock_destroy(g->bt_story.clock);
	sfClock_destroy(g->bt_setup.clock);
	sfClock_destroy(g->bt_save.clock);
	sfClock_destroy(g->bt_end.clock);
	sfClock_destroy(g->bt_quit_m.clock);
	sfView_destroy(g->view);
	sfMusic_destroy(g->music_ts);
}
