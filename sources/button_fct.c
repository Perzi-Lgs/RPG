/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** button_fct.c
*/

#include "my_rpg.h"

int play(window_t *window, main_menu_t *menu)
{
	(void)window;
	(void)menu;
	CLEAR(window->RenderWindow, sfBlack);
	return (1);
}

int load(window_t *window, main_menu_t *menu)
{
	DRAW_SPRITE(window->RenderWindow, menu->background[1].sprite, NULL);
	display_sprite(&menu->how_to_play, window);
	DRAW(window->RenderWindow);
	while (!sfKeyboard_isKeyPressed(sfKeyEscape));
	CLEAR(window->RenderWindow, sfBlack);
	return (0);
}

int setting(window_t *window, main_menu_t *menu)
{
	sfRectangleShape **sound = malloc(sizeof(sfRectangleShape *) * 2);

	if (!sound || create_sound_set(sound, menu) == -1)
		return (84);
	change_txt(menu, sfTrue);
	sfSleep(sfSeconds(0.2));
	for (int actif = 0; actif == 0;) {
		draw1_menu(menu, window);
		actif = event_mouse_set(window, menu, sound);
		DRAW_SPRITE(window->RenderWindow,\
			menu->background[1].sprite, NULL);
		for (int i = 0; i < 2; i++) {
			DRAW_TXT(window->RenderWindow,\
				menu->menu_text.main_menu_text[i], NULL);
			DRAW_REC(window->RenderWindow, sound[i], NULL);
		}
	}
	change_txt(menu, sfFalse);
	sfSleep(sfSeconds(0.6));
	return (0);
}

int quit(window_t *window, main_menu_t *menu)
{
	(void)menu;
	sfRenderWindow_close(window->RenderWindow);
	return (-1);
}
