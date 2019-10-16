/*
** EPITECH PROJECT, 2017
** dante
** File description:
** sound_settings.c
*/

#include "my_rpg.h"

void init_value(sfVector2f *value)
{
	value[0].x = 300;
	value[0].y = 10;
	value[1].x = 20;
	value[1].y = 25;
	value[2].x = 5;
	value[2].y = 10;
	value[3].x = 1360;
	value[3].y = 520;
}

int create_sound_set(sfRectangleShape **sound, main_menu_t *menu)
{
	sfVector2f *value = malloc(sizeof(sfVector2f) * 5);
	float music = sfMusic_getVolume(menu->music);

	if (!value)
		return (-1);
	init_value(value);
	value[4].x = (300*music/100)+1360;
	value[4].y = 520;
	sound[0] = create_rect_entity(value[0]);
	sound[1] = create_rect_entity(value[1]);
	sfRectangleShape_setFillColor(sound[0], sfWhite);
	sfRectangleShape_setOutlineThickness(sound[1], 2);
	sfRectangleShape_setOutlineColor(sound[1],\
		sfColor_fromRGBA(138, 139, 129, 255));
	sfRectangleShape_setFillColor(sound[1], sfWhite);
	sfRectangleShape_setOrigin(sound[1], value[2]);
	sfRectangleShape_setPosition(sound[0], value[3]);
	sfRectangleShape_setPosition(sound[1], value[4]);
	return (0);
}

void change_volume(sfRectangleShape **sound, main_menu_t *menu,\
	window_t *window)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(window->RenderWindow);
	sfVector2f move = {0, 0};
	sfVector2f left_pos = {1359, 520};
	sfVector2f right_pos = {1659, 520};

	while (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
		set_pos(&pos, &move, window, sound);
		if (pos.x < 1360) {
			sfMusic_setVolume(menu->music, 0);
			sfRectangleShape_setPosition(sound[1], left_pos);
		} else if (pos.x > 1660) {
			sfMusic_setVolume(menu->music, 100);
			sfRectangleShape_setPosition(sound[1], right_pos);
		} else
			sfRectangleShape_move(sound[1], move);
		sfMusic_setVolume(menu->music,\
			(sfRectangleShape_getPosition(sound[1]).x - 1360)\
			* 100/300);
		draw_settings(window, menu, sound);
	}
}

void change_txt(main_menu_t *menu, sfBool open)
{
	char *str[5] = {"Parametres", "\tSound", "Frame Rate ",\
	"Difficulte", "Quitter"};
	char *asset[5] = {"Menu", "Nouvelle Partie", "Comment jouer ?",\
	"Parametres", "Quitter"};

	if (open == sfTrue) {
		for (int i = 0; i < 5; i++) {
			sfText_setString(menu->menu_text.main_menu_text[i],\
				str[i]);
				sfText_setColor(menu->menu_text.\
					main_menu_text[i], sfWhite);
		}
	} else {
		for (int i = 0; i < 5; i++) {
			sfText_setString(menu->menu_text.main_menu_text[i],\
				asset[i]);
			sfText_setColor(menu->menu_text.main_menu_text[i],\
				sfWhite);
		}
	}
}
