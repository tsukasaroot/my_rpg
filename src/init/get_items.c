/*
** EPITECH PROJECT, 2017
** get items
** File description:
** c file
*/

#include "my_rpg.h"

char *re_alloc2(char *str, char c)
{
	char *new = malloc(sizeof(char) * (my_strlen(str) + 2));
	int i = 0;

	while (str != NULL && str[i] != '\0') {
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (str != NULL)
		free(str);
	return (new);
}

char *get_file2(int fd)
{
	int i = 0;
	int size = 0;
	char buff[1];
	char *str = NULL;

	while ((size = read(fd, buff, 1)) > 0) {
		str = re_alloc2(str, buff[0]);
		i++;
	}
	if (str != NULL)
		str[i] = '\0';
	return (str);
}

void get_items_part2(p_game *g, p_item **itm, char **tab, int i)
{
	p_item *new;

	if (tab[i] == NULL)
		return;
	if (is_nbr(tab[i]) == 0 || tab[i + 1] == NULL ||
		is_nbr(tab[i + 1]) == 0 || tab[i + 2] == NULL)
		return;
	if ((new = malloc(sizeof(p_item))) == NULL)
		return;
	new->id = get_nbr(tab[i]);
	new->power = get_nbr(tab[i + 1]);
	new->name = my_strcpy(tab[i + 2]);
	new->next = NULL;
	*itm = new;
	get_items_part2(g, &new->next, tab, i + 3);
}

int get_items(p_game *g)
{
	int fd = 0;
	char *str = NULL;
	char **tab = NULL;

	if ((fd = open("objs/items.itm", O_RDONLY)) == -1)
		return (84);
	if ((str = get_file2(fd)) == NULL)
		return (84);
	if ((tab = my_str_to_wordtab(str, ':')) == NULL)
		return (84);
	get_items_part2(g, &g->itm, tab, 0);
	free(str);
	free(tab);
	return (0);
}
