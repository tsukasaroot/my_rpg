/*
** EPITECH PROJECT, 2018
** game_destroy
** File description:
** c file
*/

#include "my_rpg.h"

void game_destroy_part2(p_game *g)
{
	free_img(&g->i_start_menu);
	free_img(&g->i_dark_screen);
	free_img(&g->i_game_menu);
	free_img(&g->i_bg_fight1);
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
	free_img(&g->i_bt_music_l);
	free_img(&g->i_bt_music_r);
	free_img(&g->i_skill_choice);
}

void game_destroy_part3(p_game *g)
{
	free_img(&g->i_mob1);
	free_img(&g->i_mob2);
	free_img(&g->i_cursor);
	free_img(&g->i_pseudo);
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
	sfClock_destroy(g->player_clock);
	sfClock_destroy(g->playera_clock);
	sfMusic_stop(g->music_land);
}

void game_destroy(p_game *g)
{
	sfTexture_destroy(g->t_map);
	sfSprite_destroy(g->s_map);
	game_destroy_part2(g);
	game_destroy_part3(g);

	if (sfMusic_getStatus(g->music_land) == 0)
		sfMusic_destroy(g->music_land);
	sfMusic_stop(g->music_button);
	if (sfMusic_getStatus(g->music_button) == 0)
		sfMusic_destroy(g->music_button);
	sfMusic_stop(g->music_fight);
	if (sfMusic_getStatus(g->music_fight) == 0)
		sfMusic_destroy(g->music_fight);
	sfView_destroy(g->view);
	sfMusic_destroy(g->music_ts);
}
