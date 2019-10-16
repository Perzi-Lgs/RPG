/*
** EPITECH PROJECT, 2018
** include
** File description:
** rpg.h
*/

#ifndef _RPG_PARSER_
#define _RPG_PARSER_

#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>

#include "libmy.h"
#include "struct.h"

/*
** Const values for items creation.
*/
static const int FILE_SIZE = 906;
static const int NBR_ITEMS = 6;
static const int ITEM_NAME = 18;
static const int NBR_STATS = 3;
static const int NBR_SPRITE = 50;
static const int LEVEL = 0;
static const int ATTACK = 1;
static const int DEFENSE = 2;

/*
** Const values for monsters creation.
*/
static const int NBR_MOBS = 4;
static const int MOB_NAME = 50;
static const float COORD = 4.0;

/*
** Const values for Generation mob
*/

enum {
	BEGINNER, INTERMEDIATE, ADVANCED
};

all_armors_t *create_armors(void);
all_armors_t *malloc_armors(void);
int fill_sword(all_armors_t *, char **, int);
int fill_shield(all_armors_t *, char **, int);
int fill_body_armor(all_armors_t *, char **, int);

monsters_t *create_monsters(void);
monsters_t *malloc_monsters(void);
monsters_t *fill_mobs(monsters_t *, char **);

#endif /* _RPG_PARSER_ */
