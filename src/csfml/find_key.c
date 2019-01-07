/*
** EPITECH PROJECT, 2018
** find key
** File description:
** c file
*/

#include "my_rpg.h"

char *find_spe_key(int key)
{
	char *res = NULL;

	switch (key) {
		case 71:
			res = my_strcpy("KEY LEFT");
			break;
		case 72:
			res = my_strcpy("KEY RIGHT");
			break;
		case 73:
			res = my_strcpy("KEY UP");
			break;
		case 74:
			res = my_strcpy("KEY DOWN");
			break;
	}
	return (res);
}

char *find_key(int key)
{
	char *res = NULL;

	if (key < 27) {
		res = malloc(sizeof(char) * 2);
		res[0] = key + 65;
		res[1] = 0;
	} else
		return (find_spe_key(key));
	return (res);
}
