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
#define MY_RPG_H

typedef struct s_player *p_player;

typedef struct img {
	sfTexture* texture;
	sfSprite* sprite;
	sfVector2f pos;
	sfVector2f relative_pos;
	sfIntRect rect;
}		p_img;

typedef struct button {
	int status;
	sfClock *clock;
}		p_button;

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
	int status;
	int status_start_menu;
	int status_game_menu;
	unsigned int gold;
	sfMusic* music_ts;
	p_player *p;
	char **map;
	sfView *view;
	int player_direction;
	int player_move;
	sfClock *player_clock;
	p_img i_nbr_gold;
	p_img i_player;
	p_img i_start_menu;
	p_img i_bg_menu;
	p_img i_dark_screen;
	p_img i_game_menu;
	p_button bt_load;
	p_img i_bt_load;
	p_button bt_option;
	p_img i_bt_option;
	p_button bt_quit;
	p_img i_bt_quit;
	p_button bt_start;
	p_img i_bt_start;
	p_button bt_item;
	p_img i_bt_item;
	p_img i_menu_item;
	p_button bt_skills;
	p_img i_bt_skills;
	p_img i_menu_skill;
	p_button bt_equip;
	p_img i_bt_equip;
	p_img i_menu_equip;
	p_button bt_status;
	p_img i_bt_status;
	p_img i_menu_status;
	p_button bt_story;
	p_img i_bt_story;
	p_img i_menu_story;
	p_button bt_setup;
	p_img i_bt_setup;
	p_img i_menu_setup;
	p_button bt_save;
	p_img i_bt_save;
	p_img i_menu_save;
	p_button bt_end;
	p_img i_bt_end;
	p_button bt_quit_m;
	p_img i_bt_quit_m;
	sfTexture* t_map;
	sfSprite* s_map;
	sfVector2f p_map;
	sfIntRect rect_map;
	sfTexture **title_scr;
	sfSprite *sprite_tx;
	float second_tx;
	int count_tx;
	sfClock *clock_tx;
}		p_game;

void my_putchar(char);
void my_put_str(char *);
void my_put_nbr(int);
char *my_strcpy(char *);
int get_nbr(char *);
int my_strcmp(char *, char *);
void bad_argument(int);
void flag_h(void);
char **get_map(char *, int *, int *);
char *get_nextline(int);
int set_img_sprite(p_img *, const char *);
int set_img_pos(p_img *, int, int);
int set_img_rect_pos(p_img *, int, int);
int set_img_rect_size(p_img *, int, int);
void set_img_relative_pos(p_game *, p_img *);
void set_img_center(p_game *g, p_img *);
int check_button(p_game *, sfEvent *, p_button *, p_img *);
void free_img(p_img *);
int game_loop(char **, int, int);
void my_event(p_game *);
int game_init(p_game *, int, int);
void reset_status(p_game *);
void update_title_screen(p_game *);
void update_start_menu(p_game *);
void update_game(p_game *);
void update_player(p_game *);
void update_menu(p_game *);
void update_menu_item(p_game *);
void update_menu_skill(p_game *);
void update_menu_equip(p_game *);
void update_menu_status(p_game *);
void update_menu_story(p_game *);
void update_menu_setup(p_game *);
void update_menu_save(p_game *);
void update_sub_menu(p_game *);
void draw_start_menu(p_game *);
void draw_start_menu_option(p_game *);
void draw_menu(p_game *);
void draw_menu_item(p_game *);
void draw_menu_skill(p_game *);
void draw_menu_equip(p_game *);
void draw_menu_status(p_game *);
void draw_menu_story(p_game *);
void draw_menu_setup(p_game *);
void draw_menu_save(p_game *);
void draw_game(p_game *);
void draw_map(p_game *);
void draw_button(p_game *, p_button *, p_img *);
void draw_nbr(p_game *, p_img *, unsigned int, sfVector2f);
void key_title_screen(p_game *, sfEvent *);
void key_game(p_game *, sfEvent *);
void key_menu(p_game *, sfEvent *);
void button_start_menu(p_game *, sfEvent *);
void button_game_menu(p_game *, sfEvent *);
int player_can_walk(p_game *);
void game_destroy(p_game *);
void free_tab(char **);
int my_strlen(char *);
void create_title_screen(p_game *);
void draw_title_screen(p_game *);

#endif /* MY_RPG_H */
