/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** init_world.c
*/

#include "my_rpg.h"
#include "character.h"

int start_new_level(window_t *window, int **map, game_t *game)
{
	int ret = 0;
	map_t *s_map = malloc(sizeof(map_t));
	fsprites_t sprites;

	create_floor_sprites(&sprites);
	if (init_struct_map(map, s_map, window, sfTrue) == -1)
		return (84);
	while (ret == 0) {
		ret = world_event(window, s_map, &sprites, game);
		draw_map(window, s_map, &sprites);
	}
	if (ret == 3)
		return (0);
	return (ret);
}

int new_level(window_t *window, game_t *game)
{
	char **save = malloc_tab(50, 50);
	int fd = open(MAP2_H, O_RDWR);
	int **map;

	if (fd < 0 || save == NULL)
		return (1);
	save[0] = get_next_line(fd);
	if (save[0] != NULL) {
		if (fill_map(save, fd, 50) == 1)
			return (1);
		map = transform_save(save, 50);
		close(fd);
		return (start_new_level(window, map, game));
	}
	return (0);
}
