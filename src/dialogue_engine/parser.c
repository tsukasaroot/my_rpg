/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** parser file
*/

#include "my_rpg.h"

int file_size(char *path)
{
	int fd = 0;
	char c;
	int i = 0;

	fd = open(path, O_RDONLY);
	if (fd != -1) {
		i = i + 2;
		while (read(fd, &c, 1) > 0)
			if (c == '\n')
				i++;
		close(fd);
	} else {
		my_put_str("File open error\n");
		return (84);
	}
	return (i);
}

char **parse_script(char **dialogue, int file_len)
{
	int i = 0;
	int j = 0;
	char **dialogue_cpy = NULL;

	dialogue_cpy = malloc(sizeof(char *) * (file_len + 1));
	while (dialogue[i] != NULL) {
		if (dialogue[i][0] == '"' || dialogue[i][0] == '<') {
			dialogue_cpy[j] = my_strcpy(dialogue[i]);
			j++;
		}
		i++;
	}
	dialogue_cpy[j] = NULL;
	free_tab(dialogue);
	return (dialogue_cpy);
}

char *str_replace(char *s, int i, char *name)
{
	char *s_cpy = 0;
	int j = 0;
	int k = 0;

	s_cpy = malloc(sizeof(char) * (my_strlen(s) + my_strlen(name) + 1));
	while (j < i) {
		s_cpy[j] = s[j];
		j++;
	}
	while (name[k] != '\0')
		s_cpy[j++] = name[k++];
	i += 2;
	while (s[i] != '\0') {
		s_cpy[j] = s[i];
		j++;
		i++;
	}
	s_cpy[j] = '\0';
	free(s);
	return (s_cpy);
}
