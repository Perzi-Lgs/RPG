/*
** EPITECH PROJECT, 2017
** dante
** File description:
** draw_settings.c
*/

#include "my_rpg.h"

void draw_settings(window_t *window, main_menu_t *menu,\
	sfRectangleShape **sound)
{
	draw1_menu(menu, window);
	DRAW_SPRITE(window->RenderWindow, menu->background[1].sprite, NULL);
	for (int i = 0; i < 2; i++)
		DRAW_REC(window->RenderWindow, sound[i], NULL);
	for (int i = 0; i < 5; i++)
		DRAW_TXT(window->RenderWindow,\
			menu->menu_text.main_menu_text[i], NULL);
	DRAW_REC(window->RenderWindow, sound[1], NULL);
	DRAW(window->RenderWindow);
	CLEAR(window->RenderWindow, sfBlack);
}

void draw_settings_without_clear(window_t *window, main_menu_t *menu,\
	sfRectangleShape **sound)
{
	draw1_menu(menu, window);
	DRAW_SPRITE(window->RenderWindow, menu->background[1].sprite, NULL);
	for (int i = 0; i < 2; i++)
		DRAW_REC(window->RenderWindow, sound[i], NULL);
	for (int i = 0; i < 5; i++)
		DRAW_TXT(window->RenderWindow,\
			menu->menu_text.main_menu_text[i], NULL);
	DRAW_REC(window->RenderWindow, sound[1], NULL);
	DRAW(window->RenderWindow);
}
