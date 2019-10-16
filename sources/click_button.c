/*
** EPITECH PROJECT, 2017
** my_world
** File description:
** menu
*/

#include "my_rpg.h"

void color_text(main_menu_t *menu, window_t *window, int i)
{
	DRAW_VERTEX(window->RenderWindow, menu->overlay.vert[i], NULL);
	sfText_setColor(menu->menu_text.main_menu_text[i+1], sfBlack);
}

sfBool cursor_on_button(sfRectangleShape *rect, sfVector2i clickPos)
{
	sfVector2f size = sfRectangleShape_getSize(rect);
	sfVector2f pos_rect = sfRectangleShape_getPosition(rect);

	if (clickPos.x >= pos_rect.x &&
		clickPos.x <= (pos_rect.x + size.x) &&
		clickPos.y >= pos_rect.y &&
		clickPos.y <= pos_rect.y + size.y) {
		return (sfTrue);
	}
	return (sfFalse);
}

int button_clicked(window_t *window, main_menu_t *menu, int i)
{
	int (*fct_ptr[4])(window_t *window, main_menu_t *menu) = {play, load,\
		setting, quit};

	if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
		return (fct_ptr[i](window, menu));
	return (0);
}

int on_button(window_t *window, main_menu_t *menu)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(window->RenderWindow);

	for (int i = 0; i < 4; i++) {
		if (cursor_on_button(menu->rec[i], pos) == sfTrue) {
			color_text(menu, window, i);
			return (button_clicked(window, menu, i));
		} else
			sfText_setColor(menu->menu_text.main_menu_text[i+1],\
				sfWhite);
	}
	return (0);
}
