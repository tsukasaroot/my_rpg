/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** dialogue engine
*/

#include "my_rpg.h"

char **get_file(int file, int file_len)
{
	char **dialogue = NULL;
	int j = 0;

	dialogue = malloc(sizeof(char *) * (file_len + 1));
	dialogue[j] = get_nextline(file);
	while (dialogue[j++] != NULL)
		dialogue[j] = get_nextline(file);
	dialogue[j] = NULL;
	return (dialogue);
}

int use_dialogue(char **dialogue)
{
	int i = 0;

	while (dialogue[i] != NULL) {
		my_put_str(dialogue[i++]);
		my_put_str("\n");
	}
}

char **name_replace(char **dialogue, char *name)
{
	int i = 0;
	int j = 0;

	while (dialogue[i] != NULL) {
		while (dialogue[i][j] != '\0') {
			if (dialogue[i][j] == '/' && dialogue[i][j + 1] == 'h' && dialogue[i][j + 2] != 'i')
				dialogue[i] = str_replace(dialogue[i], j, name);
			j++;
		}
		j = 0;
		i++;
	}
	return (dialogue);
}

int wrapper(char *path, char *name)
{
	int file_len = 0;
	int file = 0;
	char **dialogue = NULL;

	file_len = file_size(path);
	file = open(path, O_RDONLY);
	if (file != 0) {
		dialogue = get_file(file, file_len);
		dialogue = parse_script(dialogue, file_len);
		dialogue = name_replace(dialogue, name);
		close(file);
	} else {
		my_put_str("Script file not found\n");
		return (84);
	}
	use_dialogue(dialogue);
	free_tab(dialogue);
	return (0);
}

int main(void)
{
	char *name = "Tsukasa";

	my_put_str("Prologue\n");
	wrapper("../../scripts/S_00.sc", name);
	my_put_str("\nQuest\n");
	wrapper("../../scripts/S_01.sc", name);
	return (0);
}
