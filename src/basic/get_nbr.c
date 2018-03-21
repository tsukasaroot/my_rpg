/*
** EPITECH PROJECT, 2018
** get_nbr
** File description:
** c file
*/

#include "my_rpg.h"

int get_nbr(char *str)
{
	int i = 0;
	int res = 0;

	while (str[i] >= 48 && str[i] <= 57) {
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}
