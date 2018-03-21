/*
** EPITECH PROJECT, 2018
** bad_argument
** File description:
** c file
*/

#include "my_rpg.h"

void bad_argument(int argc)
{
	my_put_str("./my_rpg:\tbad arguments: ");
	my_put_nbr(argc - 1);
	my_put_str(" given but 1 is required\nretry with -h\n84\n");
}
