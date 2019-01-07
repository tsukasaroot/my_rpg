/*
** EPITECH PROJECT, 2018
** create transition battle
** File description:
** c file
*/

#include "my_rpg.h"

void create_tb(p_game *g)
{
	g->tb[0] = sfTexture_createFromFile("image/tb/tb1.png", NULL);
	g->tb[1] = sfTexture_createFromFile("image/tb/tb2.png", NULL);
	g->tb[2] = sfTexture_createFromFile("image/tb/tb3.png", NULL);
	g->tb[3] = sfTexture_createFromFile("image/tb/tb4.png", NULL);
	g->tb[4] = sfTexture_createFromFile("image/tb/tb5.png", NULL);
	g->tb[5] = sfTexture_createFromFile("image/tb/tb6.png", NULL);
	g->tb[6] = sfTexture_createFromFile("image/tb/tb7.png", NULL);
	g->tb[7] = sfTexture_createFromFile("image/tb/tb8.png", NULL);
	g->tb[8] = sfTexture_createFromFile("image/tb/tb9.png", NULL);
	g->tb[9] = sfTexture_createFromFile("image/tb/tb10.png", NULL);
	g->tb[10] = sfTexture_createFromFile("image/tb/tb11.png", NULL);
	g->tb[11] = sfTexture_createFromFile("image/tb/tb12.png", NULL);
	g->tb[12] = sfTexture_createFromFile("image/tb/tb13.png", NULL);
	g->tb[13] = sfTexture_createFromFile("image/tb/tb14.png", NULL);
	g->tb[14] = sfTexture_createFromFile("image/tb/tb15.png", NULL);
	g->tb[15] = sfTexture_createFromFile("image/tb/tb16.png", NULL);
	g->tb[16] = sfTexture_createFromFile("image/tb/tb17.png", NULL);
	g->tb[17] = sfTexture_createFromFile("image/tb/tb18.png", NULL);
}

void create_transition_battle(p_game *g)
{
	g->tb = malloc(sizeof(sfTexture *) * 18);
	create_tb(g);
}
