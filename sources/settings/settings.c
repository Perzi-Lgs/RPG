/*
** EPITECH PROJECT, 2017
** dante
** File description:
** settings.c
*/

#include "my_rpg.h"

void set_pos(sfVector2i *pos, sfVector2f *move, window_t *window,\
	sfRectangleShape **sound)
{
	*pos = sfMouse_getPositionRenderWindow(window->RenderWindow);
	move->x = pos->x - sfRectangleShape_getPosition(sound[1]).x;
}

int button_settings(window_t *window, main_menu_t *menu, int i)
{
	int (*fct_ptr[2])(window_t *window, main_menu_t *menu) = {play, load};

	if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
		if (i == 3)
			return (-1);
		else
			return (fct_ptr[i-1](window, menu));
	}
	return (0);
}

int event_mouse_set(window_t *window, main_menu_t *menu,\
	sfRectangleShape **sound)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(window->RenderWindow);

	CLEAR(window->RenderWindow, sfBlack);
	draw_settings(window, menu, sound);
	if (cursor_on_button(sound[1], pos) == sfTrue)
		change_volume(sound, menu, window);
	for (int i = 2; i < 4; i++) {
		if (cursor_on_button(menu->rec[3], pos) == sfTrue) {
			color_text(menu, window, 3);
			return (button_settings(window, menu, 3));
		}
		if (cursor_on_button(menu->rec[i], pos) == sfTrue) {
			color_text(menu, window, i);
			return (0);
		} else
			sfText_setColor(menu->menu_text.main_menu_text[i+1],\
				sfWhite);
		draw_settings(window, menu, sound);
	}
	return (0);
}
