/*
** EPITECH PROJECT, 2017
** my_rpg header
** File description:
** header file
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

typedef struct s_var {
	int i;
	int a;
	int b;
}		t_var;

typedef struct s_particules {
	int x;
	int y;
	int time;
	int last_time;
	struct s_particules *next;
}		t_particules;

typedef struct s_spells {
	char *SPELL[11];
	char *DESCRIPTION[11];
	int MP_COST[11];
	int CD[11];
	int EFFECT_LAST[11];
	int DECR_HP[11];
	int DECR_ATK[11];
	int ATK_MOD[11];
	int TRIGGER[11];
	int UP_CC[11];
}		t_spells;

typedef struct s_class_stat {
	char *name;
	int ATK;
	int DEF;
	int CRIT;
	int HEALTH;
	int HP;
	int MANA;
	int SPEED;
	int weapon_pow;
	int weapon_id;
	int shield;
	int chestplate;
	int helmet;
	int gloves;
	struct s_class_stat *next;
}		t_class_stat;

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
	int sprite;
}		p_stat;

typedef struct s_mob {
	int HP;
	int MANA;
	int ATK;
	int ATKSPE;
	int DEF;
	int DEFSPE;
	int SPEED;
	int CRIT;
	int sprite;
	struct s_mob *next;
}		p_mob;


typedef struct s_item {
	int id;
	int power;
	char *name;
	sfVector2f pos;
	struct s_item *next;
}		p_item;

struct s_player {
	int unlook;
	sfTexture* texture;
	sfSprite* sprite;
	p_stat stats;
	p_player next;
};

typedef struct s_game {
	sfRenderWindow *window;
	int fight_turn;
	t_particules *parts;
	p_img i_parts;
	sfClock *parts_clock;
	int last_parts;
	t_class_stat *class;
	t_spells spells[4];
	p_item *itm;
	p_item *itm_select;
	struct s_class_stat *select_perso;
	p_item *inventory;
	p_img i_items;
	int level;
	int xp;
	char *player_name;
	int status;
	int status_intro;
	int status_start_menu;
	int status_game_menu;
	int status_enter_zone;
	int option_select;
	int skill_select;
	int change_key;
	int actual_zone;
	int zone;
	int boss_zone;
	int key_press_move_up;
	int key_press_move_down;
	int key_press_move_left;
	int key_press_move_right;
	unsigned int gold;
	sfMusic* music_ts;
	sfMusic* music_land;
	sfMusic* music_button;
	sfMusic* music_fight;
	p_player *p;
	char **map;
	char **boss_map;
	char **f_boss_map;
	sfVector2f p_boss_map;
	sfVector2f p_fboss_map;
	sfVector2f p_map_old;
	sfView *view;
	int player_direction;
	int player_move;
	sfClock *player_clock;
	sfClock *playera_clock;
	p_img i_dialogue;
	p_img i_pseudo;
	p_img i_pnj[5];
	p_img i_cursor;
	p_img i_nbr_gold;
	p_img i_nbr_silver;
	p_img i_player;
	p_img i_start_menu;
	p_img i_bg_menu;
	p_img i_dark_screen;
	p_img i_bg_fight1;
	p_img i_game_menu;
	p_button bt_load;
	p_img i_bt_load;
	p_img i_face_1;
	p_img i_face_2;
	p_img i_face_3;
	p_img i_face_4;
	p_img i_blackscreen;
	p_button bt_option;
	p_img i_bt_option;
	p_button bt_quit;
	p_img i_bt_quit;
	p_button bt_start;
	p_img i_bt_start;
	p_button bt_item;
	p_img i_bt_item;
	p_button bt_plus;
	p_img i_bt_plus;
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
	p_img i_bt_music_l;
	p_img i_bt_music_r;
	p_button bt_ch_itm;
	p_img i_bt_ch_itm;
	int music_volume;
	sfTexture* t_map;
	sfSprite* s_map;
	sfTexture* t_boss_map;
	sfSprite* s_boss_map;
	sfTexture* t_f_boss_map;
	sfSprite* s_f_boss_map;
	sfVector2f p_map;
	sfIntRect rect_map;
	sfTexture **title_scr;
	sfTexture **tb;
	sfSprite *sprite_tx;
	float second_tx;
	int count_tx;
	sfClock *clock_tx;
	p_mob *mob;
	p_stat *character;
	int fight_mob;
	int nb_of_mob;
	sfVector2f p_mob1;
	sfVector2f p_mob2;
	sfVector2f p_mob3;
	sfVector2f p_mob4;
	sfVector2f p_char1;
	sfVector2f p_char2;
	sfVector2f p_char3;
	sfVector2f p_char4;
	p_img i_skill_choice;
	p_img i_mob1;
	p_img i_mob2;
	p_img i_mob3;
	p_img i_char[5];
	//p_img i_char2;
	sfFont *font;
	sfText *text;
	sfFloatRect title_text_size;
	char *title_text;
	sfClock *title_clock;
	int key_inventory;
	int key_move_left;
	int key_move_right;
	int key_move_up;
	int key_move_down;
}		p_game;

void my_putchar(char);
void my_put_str(char *);
void my_put_nbr(int);
char **my_str_to_wordtab(char *, char);
char *my_strcpy(char *);
int is_nbr(char *);
int get_nbr(char *);
int my_strcmp(char *, char *);
void bad_argument(int);
void flag_h(void);
char **get_map(char *, int *, int *);
char *get_nextline(int);
void add_item(p_game *, char *, int, int);
void change_item(p_game *);
int set_img_sprite(p_img *, const char *);
int set_img_pos(p_img *, int, int);
int set_img_rect_pos(p_img *, int, int);
int set_img_rect_size(p_img *, int, int);
void set_img_relative_pos(p_game *, p_img *);
void set_img_center(p_game *g, p_img *);
void set_text_pos(p_game *, int, int);
void draw_text(p_game *, char *, int, int);
void draw_text_key(p_game *, int, int, int);
int check_button(p_game *, sfEvent *, p_button *, p_img *);
void free_img(p_img *);
int game_loop(char **, int, int);
void my_event(p_game *);
void my_event_click(p_game *, sfEvent *);
void event_click_skills_menu(p_game *, sfEvent *);
int game_init(p_game *, int, int, int);
int set_class(p_game *);
int get_items(p_game *);
void set_volume(p_game *);
void create_transition_battle(p_game *);
void reset_status(p_game *);
void update_title_screen(p_game *);
void update_transition_battle(p_game *);
void update_start_menu(p_game *);
void update_intro(p_game *);
void update_game(p_game *);
void update_player(p_game *);
void update_player_animation(p_game *);
void update_menu(p_game *);
void update_menu_item(p_game *);
void update_menu_skill(p_game *);
void update_menu_equip(p_game *);
void update_menu_status(p_game *);
void update_menu_story(p_game *);
void update_menu_setup(p_game *);
void update_menu_save(p_game *);
void update_sub_menu(p_game *);
void update_fight(p_game *);
void draw_sprite(p_game *, sfSprite *);
void draw_start_menu(p_game *);
void draw_start_menu_option(p_game *);
void draw_start_menu_key_option(p_game *);
void draw_start_menu_load(p_game *);
void draw_get_player_name(p_game *);
void draw_menu(p_game *);
void draw_menu_item(p_game *);
void draw_item(p_game *, p_item *, sfVector2f, int);
void draw_menu_skill(p_game *);
void draw_menu_equip(p_game *);
void draw_menu_status(p_game *);
void draw_menu_story(p_game *);
void draw_menu_setup(p_game *);
void draw_menu_save(p_game *);
void draw_menu_item(p_game *);
void draw_game(p_game *);
void draw_map(p_game *, int);
void draw_button(p_game *, p_button *, p_img *);
void draw_nbr(p_game *, p_img *, unsigned int, sfVector2f);
void draw_fight(p_game *);
void draw_transition_battle(p_game *);
void draw_zone(p_game *);
void key_title_screen(p_game *, sfEvent *);
void key_start_menu(p_game *, sfEvent *);
void key_start_menu_option(p_game *, sfEvent *);
void key_start_menu_option_key(p_game *, sfEvent *);
void key_start_menu_change_key(p_game *, sfEvent *);
void key_get_player_name(p_game *, sfEvent *);
void key_game(p_game *, sfEvent *);
void key_menu(p_game *, sfEvent *);
char *find_key(int);
int count_skills(p_game *);
int is_key_free(p_game *, sfEvent *);
void button_start_menu(p_game *, sfEvent *);
void button_game_menu(p_game *, sfEvent *);
int player_can_walk(p_game *, char **);
void player_interaction(p_game *);
void game_destroy(p_game *);
void free_tab(char **);
int my_strlen(char *);
void create_title_screen(p_game *);
void draw_title_screen(p_game *);
void fight_start(p_game *, int);
void check_player_case(p_game *, char **);
int wrapper(p_game *, char *, char *);
int file_size(char *);
char **parse_script(char **, int);
char *str_replace(char *, int, char *);
void spell_wrapper(t_class_stat **class, t_spells *spells, char *path);
char **create_path(char **path);
int file_size(char *path);
char **get_file(int file, int file_len);
void draw_stat_player(p_game *, t_class_stat *, int);
void draw_player_particules(p_game *);
void add_player_particules(p_game *, t_particules **, int);
int draw_player_particules_x(p_game *, t_particules *, int, int);
void init1(p_game *);
int init2(p_game *);
int init3(p_game *);
int init4(p_game *);
int init5(p_game *, char *, sfVideoMode);
int init6(p_game *);
int init7(p_game *);
int init8(p_game *);
int init9(p_game *);
int init10(p_game *);
int init11(p_game *);
int init12(p_game *);
int init13(p_game *);
int init14(p_game *);
int init15(p_game *);
int final_init1(p_game *, char *, sfVideoMode);
int final_init2(p_game *);
void player_cant_enter_zone(p_game *);

#endif /* MY_RPG_H */
