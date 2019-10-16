/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** include
*/

#ifndef MY_RPG
#define MY_RPG

#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>

#include "parsing_rpg.h"
#include "struct.h"

int x_coord;
int y_coord;

enum stats
{
	HP, ATK, DEF
};

enum sprite
{
	BRICK1, BRICK2, BRICK3, BRICK4, BRICK5, BRICK6, BRICK7, BRICK8,
	BRICK9, BRICK10, BRICK11, BRICK12, HARD_DIRT, SNOW_DIRT1, SNOW_DIRT2,
	ROCK_DIRT1, ROCK_DIRT2, DIRT, ROCK2_DIRT1, ROCK2_DIRT3, GRASS1, GRASS2,
	GRASS3, GRASS4, ROAD1, ROAD2, ROAD3, ROAD4, ROAD5, ROAD6, ROAD7,
	ROAD8, ROAD9, ROAD10, ROAD11, ROAD12, ROAD13, ROAD14, ROAD15, ROAD16,
	LAVA1, LAVA2, HARD_LAVA, OBSIDIAN, SAND, ROCK_SAND1, ROCK_SAND2, SAND3,
	ROCK1_SAND3, ROCK2_SAND3, DIRT2, ROCK1_DIRT2, ROCK2_DIRT2, HARD_SAND,
	HARD_SNOW_ROCK1, HARD_SNOW_ROCK2, HARD_SNOW, SNOW_ROCK1, SNOW_ROCK2,
	SNOW, STAIRS1, STAIRS2, STAIRS3, STAIRS4, STAIRS5, STAIRS6, STAIRS7,
	STAIRS8, STAIRS9, STAIRS10, STAIRS11, STAIRS12, STAIRS13, STAIRS14,
	STAIRS15, STAIRS16, STAIRS17, STAIRS18, STONE1, STONE2, STONE3,
	STONE4, STONE5, STONE6, STONE7, WATER, WOOD1, WOOD2, WOOD3, WOOD4
};

#define DRAW_TXT(a,b,c) sfRenderWindow_drawText(a,b,c);
#define DRAW_VERTEX(a,b,c) sfRenderWindow_drawVertexArray(a,b,c);
#define DRAW_REC(a,b,c) sfRenderWindow_drawRectangleShape(a,b,c);
#define DRAW_SPRITE(a,b,c) sfRenderWindow_drawSprite(a,b,c);
#define DRAW(a) sfRenderWindow_display(a);
#define CLEAR(a,b) sfRenderWindow_clear(a,b);

#define MAP_T "./map/map_t"
#define MAP_H "./map/map_h"
#define MAP2_H "./map/map2_h"
#define MAP2_T "./map/map2_t"

//quest
void begin_quest(window_t *window, pnj_t *pnj, map_t *map, fsprites_t *sprite);
void end_quest(window_t *window, pnj_t *pnj, map_t *map, fsprites_t *sprite);
void ini_pnj(fsprites_t *sprites, pnj_t *pnj);
void	set_hp_pos(sfText **text, monsters_t *monster);
sfText **init_hp(game_t *game, monsters_t *monster);
void atk_persos(game_t *game, monsters_t *monster, window_t *window,\
	rsprite_t *battleground);
void atk_mob(game_t *game, monsters_t *monster, window_t *window,\
	rsprite_t *battleground);
void	display_cbt(window_t *window, rsprite_t *btg, monsters_t *monster,\
	game_t *game);
//particule
int my_rand(int a, int b);
void update_buffer_p(buffer_part *this, sfVector2f pos);
buffer_part *new_part_buffer(int size);
void draw_atk_mob(buffer_part *this , sfRenderWindow *window);
void monster_atk(game_t *game, monsters_t *monster, window_t *window,
rsprite_t *battleground);
void draw_atk_perso(buffer_part *this , sfRenderWindow *window);
void player_atk(game_t *game, monsters_t *monster, window_t *window,
rsprite_t *battleground);
void update_vertex(buffer_part *this, uint id, sfVector2f start);
void update_buffer_m(buffer_part *this, sfVector2f pos);
void set_vertex(buffer_part *this, uint id, sfVector2f pos, int nb);
void set_part(buffer_part *this, uint id, sfVector2f pos, int nb);
uint new_part(buffer_part *this);
//create
void append_strip(map_t *map, sfVertex vertex0, sfVertex vertex1,\
	sfVertex vertex2);
int pnj_events(fsprites_t *sprites, window_t *window, map_t *map, pnj_t *pnj);
char **malloc_tab(int size_one, int size_two);
int fill_map(char **save, int fd, int size);
rsprite_t *create_btg(int index, fsprites_t *);
monsters_t generation(chara_t chara, monsters_t *mob, int zone);
int     create_sprite(rsprite_t *, char *, char *, char *);
int	windows_create(window_t *);
sfRectangleShape *create_rect_entity(sfVector2f size);
int	create_main_menu(main_menu_t *menu);
int	create_floor_sprites(fsprites_t *);
int	create_inv_sprites(gsprites_t *, textures_t *textures,
	fsprites_t *);
sfVector2f project_iso_point(float x, float y, float z);
sfVector2f create_iso_point_1(int i, int j, map_t *map);
sfVector2f create_iso_point_5(int i, int j, map_t *map);
int create_sound_set(sfRectangleShape **sound, main_menu_t *menu);

//settings
void change_volume(sfRectangleShape **sound, main_menu_t *menu,\
	window_t *window);
int event_mouse_set(window_t *window, main_menu_t *menu,\
		sfRectangleShape **sound);
int button_settings(window_t *window, main_menu_t *menu, int i);
void set_pos(sfVector2i *pos, sfVector2f *move, window_t *window,\
	sfRectangleShape **sound);
//Init
int init_fight(game_t *game,  map_t *map, window_t *window, fsprites_t *);
void change_txt(main_menu_t *menu, sfBool open);
int 	init_struct_map(int **map, map_t *s_map, window_t *, sfBool);
int	init_fondu_button(sfVertex **vertices);
void	init_vertex_array(main_menu_t *menu);
void	init_overlay_bck(main_menu_t *menu);
int	init_view(map_t *, window_t *);
int init_rectangle_menu(sfRectangleShape **rec);
sfVector2f *init_pos_menu(void);
//Display
void draw_tile(window_t *window, map_t *map, int i, int j);
void create_strip(map_t *map, int i, int j);
void    display_sprite(rsprite_t *, window_t *);
void	display_inv_sprites(window_t *, fsprites_t *, gsprites_t *, map_t *);
void	display_floor_sprites(fsprites_t *, window_t *);
void draw_settings(window_t *window, main_menu_t *menu,\
	sfRectangleShape **sound);
void draw_settings_without_clear(window_t *window, main_menu_t *menu,\
	sfRectangleShape **sound);
//Tools
int	*my_atoi_array(char *);
char *get_next_line(int fd);
int **transform_save(char **save, int size);
int my_getnbr(char const *str);
size_t my_strlen(char *str);
char *itoa(int nbr);
void	move_rect(rsprite_t *sprite, int max, int nb);
void	move_rect_neg(rsprite_t *, int, int, int);
//New game
void monster_atk(game_t *game, monsters_t *monster, window_t *window,
rsprite_t *battleground);
void player_atk(game_t *game, monsters_t *monster, window_t *window,
rsprite_t *battleground);
int draw_2d_map(window_t *window, map_t *map, fsprites_t *);
sfVector2f *create_2d_map(int i , int j, map_t *map);
sfVector2f **create_coord_texture(void);
sfVector2f project_iso_point(float x, float y, float z);
sfVector2f create_iso_point_1(int i, int j, map_t *map);
sfVector2f create_iso_point_2(int i, int j, map_t *map);
sfVector2f create_iso_point_3(int i, int j, map_t *map);
sfVector2f create_iso_point_4(int i, int j, map_t *map);
sfVector2f create_iso_point_5(int i, int j, map_t *map);
//Events
void display_cbt_text(window_t *window, sfText **hp, monsters_t *monster,
	game_t *game);
int world_event(window_t *window, map_t *s_map, fsprites_t *sprites,
	game_t *game);
int new_level(window_t *window, game_t *game);
int	event_mouse(window_t *window, main_menu_t *menu);
void 	analyse_event(window_t *window);
int on_button(window_t *window, main_menu_t *menu);
int load(window_t *window, main_menu_t *menu);
int play(window_t *window, main_menu_t *menu);
int setting(window_t *window, main_menu_t *menu);
int event_mouse(window_t *window, main_menu_t *menu);
int quit(window_t *window, main_menu_t *menu);
sfBool cursor_on_button(sfRectangleShape *rect, sfVector2i clickPos);
void draw1_menu(main_menu_t *menu, window_t *window);
void color_text(main_menu_t *menu, window_t *window, int i);
int	scenes(void);
int	floors(window_t *);
int	my_sleep(float);
int	on_button(window_t *window, main_menu_t *menu);
int	play(window_t *window, main_menu_t *menu);
int	load(window_t *window, main_menu_t *menu);
int	setting(window_t *window, main_menu_t *menu);
int	quit(window_t *window, main_menu_t *menu);
int     pause_game(window_t *, fsprites_t *, map_t *);
int **read_text(sfBool);
int	move_inv_left(gsprites_t *, int);
void	display_inventory(window_t *, fsprites_t *, game_t *);
void	set_items(int, inv_t *);
int	move_inside_inv(inv_t *, int, game_t *);
int	select_item(gsprites_t *, game_t *, int);
int	pause_menu(window_t *, fsprites_t *, map_t *);
int	pause_events();
int	init_pause(pause_t *, fsprites_t *);
void	display_pause_sprites(window_t *, pause_t *, map_t *, fsprites_t *);
int	button_initialise(button_t *, char *, char *);
void	button_state(button_t *, rsprite_t *, window_t *, int);
void	menu_state(button_t *, rsprite_t *, window_t *, map_t *);
void	cross_state(button_t *, rsprite_t *, window_t *, map_t *);
int	button_is_clicked(button_t *, window_t *, map_t *);
sfText	*create_text(sfText *, sfFont *, char *, int);
#endif
