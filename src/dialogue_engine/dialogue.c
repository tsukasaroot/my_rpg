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

void check_keys(sfEvent *event, int *i, int *b)
{
	if (event->key.code == sfKeyRight && event->type == sfEvtKeyPressed)
		*b = 1;
	if (*b == 1 && event->key.code == sfKeyRight && \
		event->type == sfEvtKeyReleased)
		*b = 2;
	if (*b == 2) {
		*b = 0;
		*i += 1;
	}
	if (event->key.code == sfKeyLeft && event->type == sfEvtKeyPressed)
		*b = 3;
	if (*b == 3 && event->key.code == sfKeyLeft && \
		event->type == sfEvtKeyReleased)
		*b = 4;
	if (*b == 4) {
		*b = 0;
		*i -= 1;
	}
	if (*i < 0)
		*i = 0;
}

int show_dialogue(p_game *g, char **dialogue)
{
	int i = 0;
	sfText *text;
	sfFont *font;
	sfEvent event;
	sfVector2f position;
	int b = 0;
	sfVector2f center = sfView_getCenter(g->view);
	sfVector2f size = sfView_getSize(g->view);

	position.x = 440 + center.x - size.x / 2;
	position.y = 700 + center.y - size.y / 2;
	font = sfFont_createFromFile("NotoSansMono-CondensedExtraLight.ttf");
	if (!font)
		return (1);
	text = sfText_create();
	sfText_setString(text, dialogue[i]);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 15);
	sfText_setPosition(text, position);
	while (dialogue[i] != NULL && sfRenderWindow_isOpen(g->window)) {
		while (sfRenderWindow_pollEvent(g->window, &event))
			if (event.type == sfEvtClosed) {
				sfRenderWindow_close(g->window);
				return (0);
			}
		sfRenderWindow_clear(g->window, sfBlack);
		if (g->status != 7 && g->status != 9)
			draw_game(g);
		set_img_relative_pos(g, &g->i_dialogue);
		draw_sprite(g, g->i_dialogue.sprite);
		sfRenderWindow_drawText(g->window, text, NULL);
		draw_text(g, "press key right to continue", 700, 860);
		sfRenderWindow_display(g->window);
		sfText_setString(text, dialogue[i]);
		check_keys(&event, &i, &b);
	}
	sfText_destroy(text);
	sfFont_destroy(font);
	return (0);
}

char **name_replace(char **dialogue, char *name)
{
	int i = 0;
	int j = 0;

	while (dialogue[i] != NULL) {
		while (dialogue[i][j] != '\0') {
			if (dialogue[i][j] == '/' && dialogue[i][j + 1] == 'h' \
				&& dialogue[i][j + 2] != 'i')
				dialogue[i] = str_replace(dialogue[i], j, name);
			j++;
		}
		j = 0;
		i++;
	}
	return (dialogue);
}

int wrapper(p_game *g, char *path, char *name)
{
	int file_len = 0;
	int file = 0;
	char **dialogue = NULL;

	file_len = file_size(path);
	file = open(path, O_RDONLY);
	if (g->player_name[0] < 'A' ||
		g->player_name[0] > 'Z')
	    g->player_name[0] -= 32;
	if (file != 0) {
		dialogue = get_file(file, file_len);
		dialogue = parse_script(dialogue, file_len);
		dialogue = name_replace(dialogue, name);
		close(file);
	} else {
		my_put_str("Script file not found\n");
		return (84);
	}
	show_dialogue(g, dialogue);
	free_tab(dialogue);
	return (0);
}
