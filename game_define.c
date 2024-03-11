/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:21:38 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 19:52:10 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imagen_define(t_game *game)
{
	game->img.wall = mlx_load_png("./imagen/wall.png");
	if (!game->img.wall)
		error_imagen (game);
	game->img.floor = mlx_load_png("./imagen/floor.png");
	game->img.col = mlx_load_png("./imagen/collect.png");
	game->img.py = mlx_load_png("./imagen/player.png");
	game->img.cloth = mlx_load_png("./imagen/cloth.png");
	game->img.hair = mlx_load_png("./imagen/hair.png");
	game->img.exit = mlx_load_png("./imagen/exit.png");
	game->img.enemy = mlx_load_png("./imagen/enemy.png");
	game->img.wall_img = mlx_texture_to_image(game->mlx, game->img.wall);
	game->img.fl_img = mlx_texture_to_image(game->mlx, game->img.floor);
	game->img.col_img = mlx_texture_to_image(game->mlx, game->img.col);
	game->img.py_img = mlx_texture_to_image(game->mlx, game->img.py);
	game->img.cloth_img = mlx_texture_to_image(game->mlx, game->img.cloth);
	game->img.hair_img = mlx_texture_to_image(game->mlx, game->img.hair);
	game->img.e_img = mlx_texture_to_image(game->mlx, game->img.exit);
	game->img.en_img = mlx_texture_to_image(game->mlx, game->img.enemy);
}

t_coord	find_object(char **map, char obj)
{
	t_coord	size;

	size.cl = 0;
	size.li = 0;
	while (map[size.li])
	{
		size.cl = 0;
		while (map[size.li][size.cl]
			&& map[size.li][size.cl] != '\n')
		{
			if (map[size.li][size.cl] == obj)
				return (size);
			size.cl++;
		}
		size.li++;
	}
	return (size);
}

t_coord	size_define(char **map)
{
	t_coord	size;

	size.cl = 0;
	size.li = 0;
	while (map[size.li])
	{
		size.cl = 0;
		while (map[size.li][size.cl]
			&& map[size.li][size.cl] != '\n')
		{
			size.cl++;
		}
		size.li++;
	}
	return (size);
}

int	collect_counter(char **map)
{
	int	i;
	int	j;
	int	cont;

	cont = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
				cont++;
			j++;
		}
		i++;
	}
	return (cont);
}

t_game	game_define(char **map)
{
	t_game	gm;

	gm.map = map;
	gm.size = size_define(map);
	gm.n = find_object(map, 'P');
	gm.e = find_object(map, 'E');
	gm.collect = 0;
	gm.total_collect = collect_counter(map);
	gm.mlx = mlx_init(gm.size.cl * 64, gm.size.li * 64, "so_long", true);
	imagen_define(&gm);
	gm.moves = 0;
	gm.c_exit = false;
	return (gm);
}
