/*
** EPITECH PROJECT, 2017
** My_rpg
** File description:
** choose_player_name.c
*/

#include "character.h"

/*
** This fct create and init a new text by creating the font and
** setting the size. The string taken as parameter is the string displayed
** by the sfText
** return value sfText * or NULL
*/

static sfText *init_name_text(char *name, sfVector2f pos)
{
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile("./pictures/anir.ttf");

	if (!text || !font)
		return (NULL);
	sfText_setCharacterSize(text, 80);
	sfText_setFont(text, font);
	sfText_setColor(text, sfBlack);
	sfText_setString(text, name);
	sfText_setPosition(text, pos);
	return (text);
}

/*
** change the string name in the struct character. The c char is the chara
** typed by the user the fct replace the old char by the new one and add
** a '_' at the end of the string
** return value void
*/

static void change_string(char *name, char c, int *index, sfText *name_print)
{
	if ((c == 8 && *index == 0) || c == 13)
		return;
	if (c == 8 && *index > 0) {
		name[*index] = '\0';
		name[*index-1] = '_';
		*index-=1;
	} else if (*index < 11) {
		name[*index] = c;
		name[*index+1] = '_';
		name[*index+2] = '\0';
		*index+=1;
	}
	sfText_setString(name_print, name);
}

static void draw_name_screen(window_t *window, sfText *name_print,\
	sfText *text, sfColor color)
{
	DRAW_TXT(window->RenderWindow, name_print, NULL);
	DRAW_TXT(window->RenderWindow, text, NULL);
	DRAW(window->RenderWindow);
	CLEAR(window->RenderWindow, color);
}

/*
** This fct is the event loop waiting for the user
** to choose is character's name. The main loop is waiting for the user to
** press the enter key and all the event to be treat
** return value 0 or 84
*/

static int write_name(window_t *window, char *name,\
	sfText *text, sfColor color)
{
	int index = my_strlen(name)+1;
	sfVector2f pos = {650, 600};
	sfText *name_print = init_name_text(name, pos);

	if (!name_print)
		return (84);
	DRAW_TXT(window->RenderWindow, text, NULL);
	DRAW_TXT(window->RenderWindow, name_print, NULL);
	DRAW(window->RenderWindow);
	while (sfRenderWindow_pollEvent(window->RenderWindow, &window->event)
	|| sfKeyboard_isKeyPressed(sfKeyReturn) != sfTrue) {
		if (window->event.type == sfEvtTextEntered) {
			change_string(name, (char)window->event.text.unicode,\
			&index, name_print);
			draw_name_screen(window, name_print, text, color);
		}
		sfSleep(sfMicroseconds(50000));
	}
	name[index] = '\0';
	return (0);
}

/*
** This fct create a fading screen and call the fct who allow to change the
** user character's name
** return value 0 or 84
*/

int choose_name_screen(window_t *window, char *name)
{
	sfColor fading_screen = sfColor_fromRGBA(0, 0, 0, 0);
	sfText *name_print;
	sfVector2f pos = {500, 300};
	sfText *text = init_name_text("Entre ton nom : ", pos);

	pos.y+=300;
	pos.x+=150;
	name_print = init_name_text(name, pos);
	if (!text || !name_print)
		return (84);
	for (int i = 0; i < 190; i++) {
		fading_screen.r = i;
		fading_screen.g = i;
		fading_screen.b = i;
		fading_screen.a = i;
		draw_name_screen(window, name_print, text, fading_screen);
	}
	if (write_name(window, name, text, fading_screen) == 84)
		return (84);
	return (0);
}
