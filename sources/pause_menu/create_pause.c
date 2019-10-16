/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** file for creating buttons and sprites fir the pause menu
*/

#include "my_rpg.h"

/*
** Const values for Pause Menu
*/
static char *BACK_PATH = "./pictures/pause2.png";
static char *MENU_PATH = "./pictures/bt_menu.png";
static char *EXIT_PATH = "./pictures/bt_exit.png";
static char *CROSS_PATH = "./pictures/cross.png";
static char *BT_POS = "0;0";
static char *BT_RECT = "0;0;622;170";
static char *BT_SIZE = "622;170";
static char *CROSS_RECT = "0;0;120;149";
static char *CROSS_SIZE = "120;149";
static char *BACK_SIZE = "0;0;800;800";

void	set_pause_pos(pause_t *pause, fsprites_t *sprites)
{
	sfVector2f pos = sfSprite_getPosition(sprites->chara.sprite);

	pause->psprites.back.pos.x = pos.x - 250;
	pause->psprites.back.pos.y = pos.y - 400;
	pause->psprites.menu.pos.x = pos.x - 150;
	pause->psprites.menu.pos.y = pos.y - 100;
	pause->psprites.exit.pos.x = pos.x - 150;
	pause->psprites.exit.pos.y = pos.y + 100;
	pause->psprites.cross.pos.x = pos.x + 390;
	pause->psprites.cross.pos.y = pos.y - 380;

}

void	set_bt_pos(pause_t *pause, fsprites_t *sprites)
{
	sfVector2f pos = sfSprite_getPosition(sprites->chara.sprite);

	pause->pbuttons.btmenu.pos.x = pos.x - 120;
	pause->pbuttons.btmenu.pos.y = pos.y - 100;
	sfRectangleShape_setPosition(pause->pbuttons.btmenu.rect,\
		pause->pbuttons.btmenu.pos);
	pause->pbuttons.btexit.pos.x = pos.x - 120;
	pause->pbuttons.btexit.pos.y = pos.y + 100;
	pause->pbuttons.btcross.pos.x = pos.x + 390;
	pause->pbuttons.btcross.pos.y = pos.y - 380;
}

int	create_pause_sprites(pause_t *pause, fsprites_t *sprites)
{
	if (create_sprite(&pause->psprites.menu, MENU_PATH,
		BT_POS, BT_RECT) == -1)
		return (-1);
	if (create_sprite(&pause->psprites.exit, EXIT_PATH,
		BT_POS, BT_RECT) == -1)
		return (-1);
	if (create_sprite(&pause->psprites.cross, CROSS_PATH,
		BT_POS, CROSS_RECT) == -1)
		return (-1);
	if (create_sprite(&pause->psprites.back, BACK_PATH,
		BT_POS, BACK_SIZE) == -1)
		return (-1);
	set_pause_pos(pause, sprites);
	return (0);
}

int	create_pause_buttons(pause_t *pause, fsprites_t *sprites)
{
	if (button_initialise(&pause->pbuttons.btexit, BT_POS, BT_SIZE) == -1)
		return (-1);
	if (button_initialise(&pause->pbuttons.btmenu, BT_POS, BT_SIZE) == -1)
		return (-1);
	if (button_initialise(&pause->pbuttons.btcross, BT_POS,\
		CROSS_SIZE) == -1)
		return (-1);
	set_bt_pos(pause, sprites);
	return (0);
}

int	init_pause(pause_t *pause, fsprites_t *sprites)
{
	if (create_pause_sprites(pause, sprites) == -1)
		return (-1);
	if (create_pause_buttons(pause, sprites) == -1)
		return (-1);
	return (0);
}
