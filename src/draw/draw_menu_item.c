/*
** EPITECH PROJECT, 2018
** draw_sub_menu
** File description:
** c file
*/

#include "my_rpg.h"

void draw_item_stat(p_game *g)
{
	sfVector2f pos;
	pos.x = 1000;
	pos.y = 300;
	draw_text(g, g->itm_select->name, 800, 260);
	draw_text(g, "power :", 800, 300);
	draw_nbr(g, &g->i_nbr_silver, g->itm_select->power, pos);
}

void draw_item(p_game *g, p_item *itm, sfVector2f pos, int nb)
{
	if (itm == NULL)
		return;
	g->i_items.rect.left = itm->id * 50;
	g->i_items.rect.width = 50;
	sfSprite_setTextureRect(g->i_items.sprite, g->i_items.rect);
	set_img_pos(&g->i_items, pos.x + 65 * nb, pos.y);
	draw_sprite(g, g->i_items.sprite);
	itm->pos.x = pos.x + 65 * nb;
	itm->pos.y = pos.y;
	if (nb > 4) {
		nb = 0;
		pos.y += 65;
	}
	draw_item(g, itm->next, pos, nb + 1);
}

void draw_menu_item(p_game *g)
{
	sfVector2f pos;
	pos.x = g->i_player.pos.x - 420;
	pos.y = g->i_player.pos.y - 190;
	set_img_center(g, &g->i_menu_item);
	sfRenderWindow_drawSprite(g->window, g->i_menu_item.sprite, NULL);
	draw_text(g, "inventory", 700, 175);
	draw_item(g, g->inventory, pos, 1);
	if (g->itm_select != NULL)
		draw_item_stat(g);
}
