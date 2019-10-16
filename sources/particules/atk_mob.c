/*
** EPITECH PROJECT, 2018
** .
** File description:
** atk.c
*/

#include "my_rpg.h"
#include "character.h"

void draw_atk_mob(buffer_part *this , sfRenderWindow *window)
{
	static sfRenderStates state;
	static  sfTexture *texture = NULL;
	if (texture == NULL) {
		texture = sfTexture_createFromFile
		("./pictures/ATK_MOB.png", NULL);
		state.shader = NULL;
		state.blendMode = sfBlendAlpha;
		state.transform = sfTransform_Identity;
		state.texture = texture;
	}
	sfRenderWindow_drawPrimitives(window,
	this->vertex, this->size, sfQuads, &state);
}

void monster_atk(game_t *game, monsters_t *monster, window_t *window,
rsprite_t *battleground)
{
	buffer_part *buffer = new_part_buffer(1000);
	sfClock *timer = sfClock_create();
	sfVector2f position = sfSprite_getPosition(monster->isprite.sprite);

	position.x += 550;
	set_part(buffer, 0, position, 0);
	while (sfTime_asSeconds(sfClock_getElapsedTime(timer)) < 3) {
		if (sfTime_asMilliseconds(sfClock_getElapsedTime(timer)) >= 10)
			update_buffer_m(buffer, position);
		display_sprite(&battleground[0], window);
		display_sprite(&battleground[1], window);
		display_sprite(&monster->isprite, window);
		display_sprite(game->player.sprite, window);
		draw_atk_mob(buffer, window->RenderWindow);
		sfRenderWindow_display(window->RenderWindow);
		sfRenderWindow_clear(window->RenderWindow, sfBlack);
	}
}
