/*
** EPITECH PROJECT, 2018
** set class
** File description:
** c file
*/

#include "my_rpg.h"

void set_class_equipement(t_class_stat *class)
{
	if (class == NULL)
		return;
	class->weapon_pow = 1;
	class->chestplate = 1;
	class->helmet = 1;
	class->gloves = 1;
	class->shield = 0;
	if (my_strcmp(class->name, "\"Knight\"")) {
		class->shield = 1;
		class->weapon_id = 0;
	}
	if (my_strcmp(class->name, "\"Knight\"") ||
		my_strcmp(class->name, "\"Slayer\""))
		class->weapon_id = 0;
	else
		class->weapon_id = 2;
	set_class_equipement(class->next);
}

void set_mod(p_game *g)
{
	g->spells[0].ATK_MOD[0] = 0;
	g->spells[0].ATK_MOD[1] = 0;
	g->spells[0].ATK_MOD[2] = 0;
	g->spells[0].ATK_MOD[3] = 0;
	g->spells[0].ATK_MOD[4] = 0;
	g->spells[0].ATK_MOD[5] = 0;
	g->spells[0].ATK_MOD[6] = 0;
	g->spells[0].ATK_MOD[7] = 0;
	g->spells[0].ATK_MOD[8] = 0;
	g->spells[0].ATK_MOD[9] = 0;
	g->spells[0].ATK_MOD[10] = 0;
	g->spells[0].ATK_MOD[11] = 0;
}

int set_class(p_game *g)
{
	char **path = NULL;

	if ((path = create_path(path)) == NULL)
		return (84);
	spell_wrapper(&g->class, &g->spells[0], path[0]);
	spell_wrapper(&g->class->next, &g->spells[1], path[1]);
	spell_wrapper(&g->class->next->next, &g->spells[2], path[2]);
	spell_wrapper(&g->class->next->next->next, &g->spells[3], path[3]);
	set_class_equipement(g->class);
	free(path);
	set_mod(g);
	return (0);
}
