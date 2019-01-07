/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** get spells + effects and class stats
*/

#include "my_rpg.h"

char **create_path(char **path)
{
	path = malloc(sizeof(char **) * (3 + 1));
	path[0] = "objs/slayer.objs";
	path[1] = "objs/knight.objs";
	path[2] = "objs/magus.objs";
	path[3] = "objs/priest.objs";
	return (path);
}

void add_class_stats(t_class_stat **class, char **word_tab)
{
	t_class_stat *new = malloc(sizeof(t_class_stat));

	*class = new;
	new->next = NULL;
	new->name = word_tab[0];
	new->ATK = get_nbr(word_tab[1]);
	new->DEF = get_nbr(word_tab[2]);
	new->CRIT = get_nbr(word_tab[3]);
	new->HEALTH = get_nbr(word_tab[4]);
	new->MANA = get_nbr(word_tab[5]);
	new->SPEED = get_nbr(word_tab[6]);
}

void get_stats(char **stats, t_class_stat **class, t_spells *spells)
{
	char **word_tab;
	int k = 0;
	int i = 0;

	word_tab = my_str_to_wordtab(stats[0], ':');
	add_class_stats(class, word_tab);
	free(word_tab);
	for (int j = 1; stats[j] != NULL; j++) {
		i = 0;
		word_tab = my_str_to_wordtab(stats[j], ':');
		spells->SPELL[k] = (word_tab[i] == NULL) ? NULL : word_tab[i++];
		spells->DESCRIPTION[k] = (word_tab[i] == NULL) ? NULL : word_tab[i++];
		spells->MP_COST[k] = (word_tab[i] == NULL) ? 0 : get_nbr(word_tab[i++]);
		spells->CD[k] = (word_tab[i] == NULL) ? 0 : get_nbr(word_tab[i++]);
		spells->EFFECT_LAST[k] = (word_tab[i] == NULL) ? 0 : get_nbr(word_tab[i++]);
		spells->DECR_HP[k] = (word_tab[i] == NULL) ? 0 : get_nbr(word_tab[i++]);
		spells->DECR_ATK[k] = (word_tab[i] == NULL) ? 0 : get_nbr(word_tab[i++]);
		spells->ATK_MOD[k] = (word_tab[i] == NULL) ? 0 : get_nbr(word_tab[i++]);
		spells->TRIGGER[k] = (word_tab[i] == NULL) ? 0 : get_nbr(word_tab[i++]);
		spells->UP_CC[k] = (word_tab[i] == NULL) ? 0 : get_nbr(word_tab[i++]);
		free(word_tab);
		k++;
	}
	spells->SPELL[k] = NULL;
}

void spell_wrapper(t_class_stat **class, t_spells *spells, char *path)
{
	char **stats = NULL;
	int fd = 0;
	int file_len = 0;

	file_len = file_size(path);
	fd = open(path, O_RDONLY);
	stats = get_file(fd, file_len);
	if (fd != 0)
		get_stats(stats, class, spells);
	else
		my_put_str("Class file not found\n");
}
