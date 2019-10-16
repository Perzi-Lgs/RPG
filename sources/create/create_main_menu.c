/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** create_main_menu.c
*/

#include "my_rpg.h"

int init_menu_text(menu_text_t *text)
{
	text->main_menu_text = malloc(sizeof(sfText *) * 5);
	sfVector2f pos = {1360, 370};
	char *asset[5] = {"Menu", "Nouvelle Partie", "Comment jouer ?",\
	"Parametres", "Quitter"};

	text->font = sfFont_createFromFile("./pictures/anir.ttf");
	if (text->main_menu_text == NULL || text->font == NULL)
		return (-1);
	for (int i = 0; i < 5; i++) {
		text->main_menu_text[i] = sfText_create();
		sfText_setFont(text->main_menu_text[i], text->font);
		if (!text->main_menu_text[i])
			return (-1);
		sfText_setString(text->main_menu_text[i], asset[i]);
		sfText_setPosition(text->main_menu_text[i], pos);
		sfText_setColor(text->main_menu_text[i], sfWhite);
		pos.y += 100;
	}
	return (0);
}

int init_background_menu(sprite_t *background)
{
	char *asset[2] = {"./pictures/bck.jpg", "./pictures/bar.png"};
	sfVector2f *pos = init_pos_menu();
	sfVector2f scale = {1.2, 1.2};

	if (!pos)
		return (-1);
	for (int i = 0; i < 2; i++) {
		background[i].texture =\
		sfTexture_createFromFile(asset[i], NULL);
		background[i].sprite = sfSprite_create();
		sfSprite_setTexture(background[i].sprite,\
			background[i].texture, sfFalse);
		sfSprite_setPosition(background[i].sprite, pos[i]);
	}
	sfSprite_setScale(background[1].sprite, scale);
	return (0);
}

int	init_menu(main_menu_t *menu)
{
	if (init_menu_text(&menu->menu_text) == -1 ||
	init_background_menu(menu->background) == -1 ||
	init_rectangle_menu(menu->rec) == -1 ||
	init_fondu_button(menu->overlay.vertices) == -1)
		return (-1);
	init_vertex_array(menu);
	init_overlay_bck(menu);
	return (0);
}

int create_main_menu(main_menu_t *menu)
{
	sfFloatRect rect = {0, 0, 1920, 1080};

	menu->view = sfView_createFromRect(rect);
	menu->background = malloc(sizeof(sprite_t) * 2);
	menu->rec = malloc(sizeof(sfRectangleShape *) * 4);
	menu->overlay.vertices = malloc(sizeof(sfVertex *) * 4);
	menu->overlay.vert = malloc(sizeof(sfVertexArray *) * 4);
	menu->music = sfMusic_createFromFile("./pictures/music1.ogg");
	if (create_sprite(&menu->how_to_play, "./pictures/how_to.png",
	"400;200", "0;0;1920;1080") == -1)
		return (-1);
	if (menu->background == NULL || menu->overlay.vertices == NULL ||\
		menu->rec == NULL || menu->overlay.vert == NULL)
		return (-1);
	init_menu(menu);
	return (0);
}
