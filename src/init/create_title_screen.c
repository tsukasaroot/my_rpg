/*
** EPITECH PROJECT, 2018
** create title screen
** File description:
** c file
*/

#include "my_rpg.h"

void create_screen(p_game *g)
{
	g->title_scr[0] = sfTexture_createFromFile("image/ts/ts1.jpg", NULL);
	g->title_scr[1] = sfTexture_createFromFile("image/ts/ts2.jpg", NULL);
	g->title_scr[2] = sfTexture_createFromFile("image/ts/ts3.jpg", NULL);
	g->title_scr[3] = sfTexture_createFromFile("image/ts/ts4.jpg", NULL);
	g->title_scr[4] = sfTexture_createFromFile("image/ts/ts5.jpg", NULL);
	g->title_scr[5] = sfTexture_createFromFile("image/ts/ts6.jpg", NULL);
	g->title_scr[6] = sfTexture_createFromFile("image/ts/ts7.jpg", NULL);
	g->title_scr[7] = sfTexture_createFromFile("image/ts/ts8.jpg", NULL);
	g->title_scr[8] = sfTexture_createFromFile("image/ts/ts9.jpg", NULL);
	g->title_scr[9] = sfTexture_createFromFile("image/ts/ts10.jpg", NULL);
	g->title_scr[10] = sfTexture_createFromFile("image/ts/ts11.jpg", NULL);
	g->title_scr[11] = sfTexture_createFromFile("image/ts/ts12.jpg", NULL);
	g->title_scr[12] = sfTexture_createFromFile("image/ts/ts13.jpg", NULL);
	g->title_scr[13] = sfTexture_createFromFile("image/ts/ts14.jpg", NULL);
	g->title_scr[14] = sfTexture_createFromFile("image/ts/ts15.jpg", NULL);
	g->title_scr[15] = sfTexture_createFromFile("image/ts/ts16.jpg", NULL);
	g->title_scr[16] = sfTexture_createFromFile("image/ts/ts17.jpg", NULL);
	g->title_scr[17] = sfTexture_createFromFile("image/ts/ts18.jpg", NULL);
	g->title_scr[18] = sfTexture_createFromFile("image/ts/ts19.jpg", NULL);
}

void create_screen2(p_game *g)
{
	g->title_scr[19] = sfTexture_createFromFile("image/ts/ts20.jpg", NULL);
	g->title_scr[20] = sfTexture_createFromFile("image/ts/ts21.jpg", NULL);
	g->title_scr[21] = sfTexture_createFromFile("image/ts/ts22.jpg", NULL);
	g->title_scr[22] = sfTexture_createFromFile("image/ts/ts23.jpg", NULL);
	g->title_scr[23] = sfTexture_createFromFile("image/ts/ts24.jpg", NULL);
	g->title_scr[24] = sfTexture_createFromFile("image/ts/ts25.jpg", NULL);
	g->title_scr[25] = sfTexture_createFromFile("image/ts/ts26.jpg", NULL);
	g->title_scr[26] = sfTexture_createFromFile("image/ts/ts27.jpg", NULL);
	g->title_scr[27] = sfTexture_createFromFile("image/ts/ts28.jpg", NULL);
	g->title_scr[28] = sfTexture_createFromFile("image/ts/ts29.jpg", NULL);
	g->title_scr[29] = sfTexture_createFromFile("image/ts/ts30.jpg", NULL);
	g->title_scr[30] = sfTexture_createFromFile("image/ts/ts31.jpg", NULL);
	g->title_scr[31] = sfTexture_createFromFile("image/ts/ts32.jpg", NULL);
	g->title_scr[32] = sfTexture_createFromFile("image/ts/ts33.jpg", NULL);
	g->title_scr[33] = sfTexture_createFromFile("image/ts/ts34.jpg", NULL);
	g->title_scr[34] = sfTexture_createFromFile("image/ts/ts35.jpg", NULL);
	g->title_scr[35] = sfTexture_createFromFile("image/ts/ts36.jpg", NULL);
	g->title_scr[36] = sfTexture_createFromFile("image/ts/ts37.jpg", NULL);
	g->title_scr[37] = sfTexture_createFromFile("image/ts/ts38.jpg", NULL);
}

void create_screen3(p_game *g)
{
	g->title_scr[38] = sfTexture_createFromFile("image/ts/ts39.jpg", NULL);
	g->title_scr[39] = sfTexture_createFromFile("image/ts/ts40.jpg", NULL);
	g->title_scr[40] = sfTexture_createFromFile("image/ts/ts41.jpg", NULL);
}

void create_title_screen(p_game *g)
{
	g->title_scr = malloc(sizeof(sfTexture *) * 41);
	create_screen(g);
	create_screen2(g);
	create_screen3(g);
}
