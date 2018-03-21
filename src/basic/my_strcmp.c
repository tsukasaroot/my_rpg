/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** c file
*/

int my_strcmp(char *str, char *cmp)
{
	int i = 0;

	while (str[i] && cmp[i] && str[i] == cmp[i])
		i++;
	if (str[i] == 0 && cmp[i] == 0)
		return (1);
	return (0);
}
