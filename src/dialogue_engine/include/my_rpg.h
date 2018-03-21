/*
** EPITECH PROJECT, 2017
** my_rpg header
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio/Music.h>

#ifndef MY_RPG_H
# define MY_RPG_H

# define FILE_LEN	100

typedef struct s_player *p_player;

typedef struct s_stat_player {
	int HEALTH;
	int MANA;
	int ATK;
	int ATKSPE;
	int DEF;
	int DEFSPE;
	int SPEED;
	int CRIT;
}		p_stat;

struct s_player {
	int unlook;
	sfTexture* texture;
	sfSprite* sprite;
	p_stat stats;
	p_player next;
};

typedef struct s_game {
	sfRenderWindow *window;
	p_player *p;
	char **map;
	sfIntRect size;
}		p_game;

void my_putchar(char);
void my_put_str(char *);
void my_put_nbr(int);
int my_strcmp(char *, char *);
void bad_argument(int);
void flag_h(void);
void game_loop(char *);
void my_event(p_game *);
int my_strlen(char *);
char *get_nextline(int fd);

#endif /* MY_RPG_H */
