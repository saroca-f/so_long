/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:50:04 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/02 18:57:32 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_case(int i, int j, t_game *gm)
{
	mlx_image_to_window(gm->mlx, gm->img.py_img, j * 64, i * 64);
	mlx_image_to_window(gm->mlx, gm->img.cloth_img, j * 64, i * 64);
	mlx_image_to_window(gm->mlx, gm->img.hair_img, j * 64, i * 64);
}

void	y_case(int i, int j, t_game *gm)
{
	mlx_image_to_window(gm->mlx, gm->img.e_img, j * 64, i * 64);
	mlx_image_to_window(gm->mlx, gm->img.py_img, j * 64, i * 64);
	mlx_image_to_window(gm->mlx, gm->img.cloth_img, j * 64, i * 64);
	mlx_image_to_window(gm->mlx, gm->img.hair_img, j * 64, i * 64);
}

void	free_gm_imag(t_game *gm)
{
	mlx_delete_texture(gm->img.wall);
	mlx_delete_texture(gm->img.floor);
	mlx_delete_texture(gm->img.exit);
	mlx_delete_texture(gm->img.col);
	mlx_delete_texture(gm->img.py);
	mlx_delete_texture(gm->img.cloth);
	mlx_delete_texture(gm->img.hair);
	mlx_delete_texture(gm->img.enemy);
	mlx_delete_image(gm->mlx, gm->img.wall_img);
	mlx_delete_image(gm->mlx, gm->img.fl_img);
	mlx_delete_image(gm->mlx, gm->img.e_img);
	mlx_delete_image(gm->mlx, gm->img.col_img);
	mlx_delete_image(gm->mlx, gm->img.py_img);
	mlx_delete_image(gm->mlx, gm->img.cloth_img);
	mlx_delete_image(gm->mlx, gm->img.hair_img);
	mlx_delete_image(gm->mlx, gm->img.en_img);
	mlx_terminate(gm->mlx);
}

void	frame(t_game *gm)
{
	int		i;
	int		j;

	i = 0;
	while (gm->map[i])
	{
		j = 0;
		while (gm->map[i][j] && gm->map[i][j] != '\n')
		{
			mlx_image_to_window(gm->mlx, gm->img.fl_img, j * 64, i * 64);
			if (gm->map[i][j] == '1')
				mlx_image_to_window(gm->mlx, gm->img.wall_img, j * 64, i * 64);
			if (gm->map[i][j] == 'C')
				mlx_image_to_window(gm->mlx, gm->img.col_img, j * 64, i * 64);
			if (gm->map[i][j] == 'E')
				mlx_image_to_window(gm->mlx, gm->img.e_img, j * 64, i * 64);
			if (gm->map[i][j] == 'P')
				p_case(i, j, gm);
			if (gm->map[i][j] == 'Y')
				y_case(i, j, gm);
			j++;
		}
		i++;
	}
}

void	game_start(char **map)
{
	t_game	gm;

	gm = game_define(map);
	if (gm.moves == 0)
		frame(&gm);
	mlx_key_hook(gm.mlx, ft_key, &gm);
	mlx_loop(gm.mlx);
	free_gm_imag(&gm);
}
