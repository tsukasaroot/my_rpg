/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** get next line
*/

#include "my_rpg.h"

char *my_realloc(char *s)
{
	char *s2;
	int i = 0;

	s2 = malloc(sizeof(char) * (my_strlen(s) + 2));
	while (s[i]) {
		s2[i] = s[i];
		i++;
	}
	s2[i + 1] = '\0';
	free(s);
	return (s2);
}

char *get_nextline(int fd)
{
	static char buffer_read[500];
	int i = 0;
	int size = 0;
	char *buff;

	if ((buff = malloc(sizeof(char))) == NULL) {
		return (NULL);
	}
	buff[0] = '\0';
	while ((size = read(fd, buffer_read, 1)) > 0 && \
		buffer_read[0] != '\n') {
		buff = my_realloc(buff);
		buff[i] = buffer_read[0];
		i++;
	}
	if (size == 0 && i == 0) {
		free(buff);
		return (NULL);
	} else
		return (buff);
}
