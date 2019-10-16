/*
** EPITECH PROJECT, 2017
** dante
** File description:
** event_two.c
*/

#include "my_rpg.h"

void ini_pnj(fsprites_t *sprites, pnj_t *pnj)
{
	pnj->pos_pnj_b = sfSprite_getPosition(sprites->pnj_b.sprite);
	pnj->pos_pnj_g = sfSprite_getPosition(sprites->pnj_g.sprite);
	pnj->pos = sfSprite_getPosition(sprites->chara.sprite);
	pnj->font = sfFont_createFromFile("./pictures/anir.ttf");
	pnj->text = sfText_create();
}

void end_quest(window_t *window, pnj_t *pnj, map_t *map, fsprites_t *sprite)
{
	char *first = "Bonjour,\n";
	char *second = "Vous voulez me donner un message de Terry?\n";
	char *third = "Merci de m'avoir donner ce message\n";
	char *last = "Je vous souhaite bonne chance pour la suite.\n";
	sfVector2f pos = {1200, 2500};

	sfText_setString(pnj->text, my_strcat(my_strcat(first, second),\
	my_strcat(third, last)));
	sfText_setFont(pnj->text, pnj->font);
	sfText_setCharacterSize(pnj->text, 50);
	sfRenderWindow_setView(window->RenderWindow, map->view);
	sfText_setPosition(pnj->text, pos);
	draw_2d_map(window, map, sprite);
	sfRenderWindow_drawText(window->RenderWindow, pnj->text, NULL);
	sfRenderWindow_display(window->RenderWindow);
}

void begin_quest(window_t *window, pnj_t *pnj, map_t *map, fsprites_t *sprite)
{
	char *first = "Bonjour, jeune aventurier, je suis Terry\n";
	char *second = "Aide-moi a transmettre un message a une amie.\n";
	char *third = "Je ne peux pas aller la voir";
	char *last = " car je dois proteger cette zone.\n";
	sfVector2f pos = {400, 3500};

	sfText_setString(pnj->text, my_strcat(my_strcat(first, second),\
	my_strcat(third, last)));
	sfText_setFont(pnj->text, pnj->font);
	sfText_setCharacterSize(pnj->text, 50);
	sfRenderWindow_setView(window->RenderWindow, map->view);
	sfText_setPosition(pnj->text, pos);
	draw_2d_map(window, map, sprite);
	sfRenderWindow_drawText(window->RenderWindow, pnj->text, NULL);
	sfRenderWindow_display(window->RenderWindow);
}
