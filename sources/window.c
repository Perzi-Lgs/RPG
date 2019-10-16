/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** window.c
*/

#include "my_rpg.h"

sfVideoMode get_mode(int w, int h, int bpp)
{
	sfVideoMode mode = { w, h, bpp };
	return (mode);
}

int windows_create(window_t *window)
{
	window->mode = get_mode(1920, 1080, 32);
	window->RenderWindow = sfRenderWindow_create(window->mode, "My RPG",
		sfResize | sfClose | sfFullscreen, NULL);
	if (!window->RenderWindow)
		return (-1);
	sfRenderWindow_setFramerateLimit(window->RenderWindow, 60);
	sfRenderWindow_setKeyRepeatEnabled(window->RenderWindow, sfFalse);
	return (0);
}

void analyse_event(window_t *window)
{
	while (sfRenderWindow_pollEvent(window->RenderWindow,\
		&window->event)) {
		if (window->event.type == sfEvtClosed ||\
			sfKeyboard_isKeyPressed(sfKeyC) == 1)
			sfRenderWindow_close(window->RenderWindow);
	}
}

int destroy_window(window_t *window)
{
	sfRenderWindow_destroy(window->RenderWindow);
	return (0);
}
