/*
** EPITECH PROJECT, 2018
** add_item
** File description:
** c file
*/

#include "my_rpg.h"

void add_item_part2(p_item **item, char *name, int id, int power)
{
	p_item *new;

	if (*item != NULL) {
		new = *item;
		add_item_part2(&new->next, name, id, power);
		return;
	}
	new = malloc(sizeof(p_item));
	*item = new;
	new->id = id;
	new->name = my_strcpy(name);
	new->power = power;
	new->next = NULL;
}

void add_item(p_game *g, char *name, int id, int power)
{
	add_item_part2(&g->inventory, name, id, power);
}
