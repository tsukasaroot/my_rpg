/*
** EPITECH PROJECT, 2018
** set volume
** File description:
** c file
*/

#include "my_rpg.h"

void set_volume(p_game *g)
{
	sfMusic_setVolume(g->music_ts, g->music_volume);
	sfMusic_setVolume(g->music_land, g->music_volume);
	sfMusic_setVolume(g->music_fight, g->music_volume);
}
