/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** str_to_wordtab
*/

#include "my_rpg.h"

int my_countword(char *str, char carac)
{
	int i = 0;
	int n = 1;

	while (str[i] != '\0' && str[i] != '\n') {
		if (str[i] == carac && str[i + 1] != '\0')
			n++;
		i++;
	}
	return (n);
}

int my_countchar(char *str, char carac)
{
	int c = 0;

	while ((str[c] != carac) && (str[c] != '\0') && (str[c] != '\n'))
		c++;
	c += 1;
	return (c);
}

void my_init_var(t_var *v)
{
	v->i = 0;
	v->a = 0;
	v->b = 0;
}

void little_whil(t_var *v, char *str, char carac)
{
	if (str[v->i] == carac || str[v->i] == '\n') {
		while (str[v->i] == carac)
			v->i++;
		v->a = v->a + 1;
		v->b = 0;
	}
}

char **my_str_to_wordtab(char *str, char carac)
{
	char  **tab;
	t_var v;

	my_init_var(&v);
	tab = malloc(sizeof(*tab) * ((my_countword(str, carac) + 1)));
	if (tab == NULL)
		return (0);
	while (str[v.i] != '\n' && str[v.i] != '\0') {
		little_whil(&v, str, carac);
		tab[v.a] = malloc(sizeof(**tab) * \
			((my_countchar(str + v.i, carac) + 1)));
		if (tab[v.a] == NULL)
			return (0);
		while ((str[v.i] != carac)  && \
			(str[v.i] != '\n') && (str[v.i] != '\0'))
			tab[v.a][v.b++] = str[v.i++];
		tab[v.a][v.b] = '\0';
	}
	tab[v.a + 1] = 0;
	return (tab);
}
