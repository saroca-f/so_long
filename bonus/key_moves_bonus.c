/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:14:59 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 18:15:59 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	person_print(int j, int i, t_game *gm)
{
	mlx_image_to_window(gm->mlx, gm->img.py_img, i * 64, j * 64);
	mlx_image_to_window(gm->mlx, gm->img.cloth_img, i * 64, j * 64);
	mlx_image_to_window(gm->mlx, gm->img.hair_img, i * 64, j * 64);
}

void	void_case(int j, int i, t_game *g)
{
	g->map[j][i] = 'P';
	person_print(j, i, g);
	if (g->c_exit == true)
	{
		g->map[g->n.li][g->n.cl] = 'E';
		mlx_image_to_window(g->mlx, g->img.e_img, g->n.cl * 64, g->n.li * 64);
		g->c_exit = false;
	}
	else
	{
		g->map[g->n.li][g->n.cl] = '0';
		mlx_image_to_window(g->mlx, g->img.fl_img, g->n.cl * 64, g->n.li * 64);
	}
}

void	c_case(int j, int i, t_game *g)
{
	g->collect = g->collect + 1;
	if (g->collect == g->total_collect)
	{
		mlx_delete_image(g->mlx, g->img.e_img);
		mlx_delete_texture(g->img.exit);
		g->img.exit = mlx_load_png("./imagen/exit2.png");
		g->img.e_img = mlx_texture_to_image(g->mlx, g->img.exit);
		mlx_image_to_window(g->mlx, g->img.e_img, g->e.cl * 64, g->e.li * 64);
	}
	g->map[j][i] = 'P';
	mlx_image_to_window(g->mlx, g->img.fl_img, i * 64, j * 64);
	person_print(j, i, g);
	if (g->c_exit == true)
	{
		g->map[g->n.li][g->n.cl] = 'E';
		mlx_image_to_window(g->mlx, g->img.e_img, g->n.cl * 64, g->n.li * 64);
		g->c_exit = false;
	}
	else
	{
		g->map[g->n.li][g->n.cl] = '0';
		mlx_image_to_window(g->mlx, g->img.fl_img, g->n.cl * 64, g->n.li * 64);
	}
}

void	e_case(int j, int i, t_game *g)
{
	if (g->collect == g->total_collect)
	{
		mlx_close_window(g->mlx);
		ft_printf("You won in ");
	}
	g->c_exit = true;
	g->map[j][i] = 'Y';
	person_print(j, i, g);
	g->map[g->n.li][g->n.cl] = '0';
	mlx_image_to_window(g->mlx, g->img.fl_img, g->n.cl * 64, g->n.li * 64);
}

void	x_case(t_game *game)
{
	ft_printf("You died in ");
	mlx_close_window(game->mlx);
}
