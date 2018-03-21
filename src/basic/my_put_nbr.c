/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** c file
*/

#include "my_rpg.h"

void my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * - 1;
	}
	if (nb >= 10)
		my_put_nbr(nb / 10);
	my_putchar(nb % 10 + 48);
}
