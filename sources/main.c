/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main file for my_rpg
*/

#include "my_rpg.h"
#include "character.h"

int event_mouse(window_t *window, main_menu_t *menu)
{
	analyse_event(window);
	return (on_button(window, menu));
}

void draw1_menu(main_menu_t *menu, window_t *window)
{
	DRAW_SPRITE(window->RenderWindow, menu->background[0].sprite, NULL);
	DRAW_VERTEX(window->RenderWindow, menu->overlay.bck, NULL);
}

void draw2_menu(main_menu_t *menu, window_t *window)
{
	DRAW_SPRITE(window->RenderWindow, menu->background[1].sprite, NULL);
	for (int i = 0; i < 5; i++)
		DRAW_TXT(window->RenderWindow,\
			menu->menu_text.main_menu_text[i], NULL);
	DRAW(window->RenderWindow);
	CLEAR(window->RenderWindow, sfBlack);
}

int menu(window_t *window, game_t *game)
{
	main_menu_t menu;
	int ret = 0;

	(void)game;
	create_main_menu(&menu);
	sfRenderWindow_setView(window->RenderWindow, menu.view);
	sfMusic_setLoop(menu.music, sfTrue);
	sfMusic_setVolume(menu.music, 50);
	sfMusic_play(menu.music);
	for (; ret == 0;) {
		draw1_menu(&menu, window);
		ret = event_mouse(window, &menu);
		draw2_menu(&menu, window);
	}
	sfMusic_destroy(menu.music);
	sfSprite_destroy(menu.background->sprite);
	return (ret);
}

int main(int __attribute__((__unused__)) ac,
char const __attribute__((__unused__))**av, char **env)
{
	x_coord = 46;
	y_coord = 46;
	if (!env[0])
		return (84);
	return (scenes());
}
