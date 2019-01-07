/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** basic functions
*/

#include "my_rpg.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_put_str(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		my_putchar(str[i++]);
}

int my_strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char *my_strcpy(char *str)
{
	int i = my_strlen(str) + 1;
	char *new = NULL;

	if (i <= 0)
		return (NULL);
	new = malloc(sizeof(char) * (i));
	i = 0;
	while (str[i]) {
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void free_tab(char **tab)
{
	int i = 0;

	if (tab == 0)
		return;
	while (tab[i]) {
		free(tab[i]);
		i++;
	}
	free(tab);
}
