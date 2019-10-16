/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** structs for my_rpg
*/

#ifndef STRUCT
#define STRUCT

#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>

#include "libmy.h"

typedef struct main_menu main_menu_t;
typedef struct sprites sprite_t;
typedef struct menu_text menu_text_t;
typedef struct overlay over_t;
typedef struct map	map_t;
typedef struct map_color map_c_t;
typedef struct s_character chara_t;
typedef struct s_inventory inventory_t;
typedef  unsigned  int  uint;

typedef struct info {
	sfVector2f speed;
	float life;
} t_info;

typedef  struct s_partBuffer{
	sfVertex *vertex;
	uint size;
	t_info *info;
} buffer_part;

typedef struct text_s {
	sfText* name;
	sfText* str;
	sfText* def;
	sfText* hp;
	sfFont* font;
}text_t;

typedef struct stat_s {
	int str;
	int def;
	int hp;
	int hp_max;

}stat_t;

typedef struct rsprite {
	sfTexture       *texture;
	sfVector2f      pos;
	sfIntRect       rect;
	sfSprite        *sprite;
}rsprite_t;

typedef struct armors {
	char *name;
	int *stats;
	char *path_sprite;
	rsprite_t isprite;
	int is_equipped;
} armors_t;

typedef struct all_armors {
	armors_t sword;
	armors_t *shield;
	armors_t *body_armors;
} all_armors_t;

typedef struct monsters {
	int zone;
	char *name;
	int *stats;
	char *path_sprite;
	rsprite_t isprite;
	float *coord;
} monsters_t;

typedef struct pnj {
	sfVector2f pos_pnj_b;
	sfVector2f pos_pnj_g;
	sfVector2f pos;
	sfFont* font;
	sfText* text;
}pnj_t;

typedef struct window {
	sfVideoMode     mode;
	sfRenderWindow  *RenderWindow;
	sfEvent         event;
	sfVector2i	posmouse;
} window_t;

struct sprites
{
	sfTexture *texture;
	sfSprite *sprite;
};

typedef struct button {
	sfRectangleShape *rect;
	sfVector2f pos;
	sfVector2f size;
} button_t;

typedef struct gsprites {
	rsprite_t back;
	rsprite_t cursor;
	rsprite_t profil;
	rsprite_t cadre;
}gsprites_t;

typedef struct fsprites {
	rsprite_t chara;
	rsprite_t pnj_b;
	rsprite_t pnj_g;
}fsprites_t;

typedef struct psprites {
	rsprite_t back;
	rsprite_t exit;
	rsprite_t menu;
	rsprite_t cross;
}psprites_t;

typedef struct pbuttons {
	button_t btexit;
	button_t btmenu;
	button_t btcross;
}pbuttons_t;

typedef struct pause_menu_s
{
	pbuttons_t pbuttons;
	psprites_t psprites;
}pause_t;

struct menu_text
{
	sfFont *font;
	sfText **main_menu_text;
};

struct overlay
{
	sfVertex **vertices;
	sfVertexArray **vert;
	sfVertex *bck_pts;
	sfVertexArray *bck;
};

struct main_menu
{
	sfView *view;
	sprite_t *background;
	rsprite_t how_to_play;
	menu_text_t menu_text;
	sfRectangleShape **rec;
	over_t overlay;
	sfMusic *music;
};

typedef struct textures
{
	sfTexture *cursor;
	sfTexture *cadre;
	sfTexture *empty;
}textures_t;

struct map_color
{
	float *tile;
	sfColor color;
	sfVector2f *n_map;
};

struct map
{
	sfTexture *texture;
	int **texture_place;
	sfVertexArray *vert;
	sfVector2f **text_coord;
	int translate_x;
	int translate_y;
	map_c_t **map;
	sfView *view;
	sfView *minimap;
	sfVector2f v_coord;
	sfMusic *music;
};

struct s_inventory
{
	size_t object_id;
	size_t object_nbr;
};

/*
** this is the struct for a character who may fight
** he got is name, sprites and two struct tab for his objects
** actually the player got 3 slot of object equippable
** The size of the inventory is 10
*/

struct s_character
{
	char *name;
	int *stat;
	rsprite_t *sprite;
	rsprite_t anim_atk;
	inventory_t *equiped;
	inventory_t *inventory;
	stat_t stats;
	int nbr_object;
	int nbr_object_equiped;
	int mob_encounter;
};

typedef struct s_game
{
	chara_t player;
	armors_t *items;
	all_armors_t *list;
	monsters_t *monsters;
	int inv_slot;
	rsprite_t slim;
}game_t;

typedef struct s_layers
{
	int layer;
	int state;
	int pos;
}layer_t;

typedef struct s_inv
{
	gsprites_t sprites;
	textures_t textures;
	int items;
}inv_t;

#endif
