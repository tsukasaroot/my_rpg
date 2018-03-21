/*
** EPITECH PROJECT, 2018
** flag
** File description:
** c file
*/

#include "my_rpg.h"

void flag_h(void)
{
	my_put_str("RPG created with CSFML.\n");
	my_put_str("\nUSAGE\n");
	my_put_str("  ./my_rpg map\n");
	my_put_str("\nOPTIONS\n");
	my_put_str("  -h                print the usage and quit.\n");
	my_put_str("\nUSER INTERACTIONS\n");
	my_put_str("  LEFT_KEY         go left.\n");
	my_put_str("  RIGHT_KEY        go right.\n");
	my_put_str("  UP_KEY           go top.\n");
	my_put_str("  DOWN_KEY         go bottom.\n");
	my_put_str("  ESCAPE_KEY       menu / inventory.\n");
	my_put_str("  I_KEY            menu / inventory.\n");
	my_put_str("  DOWN_KEY         pause game.\n");
	my_put_str("  ENTER_KEY        continue.\n");
	return;
}
