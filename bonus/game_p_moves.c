/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_p_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:47:06 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 18:48:09 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_counter(t_game *game)
{
	char	*counter;

	counter = ft_itoa(game->moves);
	mlx_put_string(game->mlx, counter, 15, 15);
	free (counter);
}

void	p_to_right(t_game *gm)
{
	mlx_delete_texture(gm->img.py);
	mlx_delete_texture(gm->img.cloth);
	mlx_delete_texture(gm->img.hair);
	mlx_delete_image(gm->mlx, gm->img.py_img);
	mlx_delete_image(gm->mlx, gm->img.cloth_img);
	mlx_delete_image(gm->mlx, gm->img.hair_img);
	gm->img.py = mlx_load_png("./imagen/player_r.png");
	gm->img.hair = mlx_load_png("./imagen/hair_r.png");
	gm->img.cloth = mlx_load_png("./imagen/cloth_r.png");
	gm->img.py_img = mlx_texture_to_image(gm->mlx, gm->img.py);
	gm->img.hair_img = mlx_texture_to_image(gm->mlx, gm->img.hair);
	gm->img.cloth_img = mlx_texture_to_image(gm->mlx, gm->img.cloth);
}

void	p_to_left(t_game *gm)
{
	mlx_delete_texture(gm->img.py);
	mlx_delete_texture(gm->img.cloth);
	mlx_delete_texture(gm->img.hair);
	mlx_delete_image(gm->mlx, gm->img.py_img);
	mlx_delete_image(gm->mlx, gm->img.cloth_img);
	mlx_delete_image(gm->mlx, gm->img.hair_img);
	gm->img.py = mlx_load_png("./imagen/player_l.png");
	gm->img.hair = mlx_load_png("./imagen/hair_l.png");
	gm->img.cloth = mlx_load_png("./imagen/cloth_l.png");
	gm->img.py_img = mlx_texture_to_image(gm->mlx, gm->img.py);
	gm->img.hair_img = mlx_texture_to_image(gm->mlx, gm->img.hair);
	gm->img.cloth_img = mlx_texture_to_image(gm->mlx, gm->img.cloth);
}

void	p_to_up(t_game *gm)
{
	mlx_delete_texture(gm->img.py);
	mlx_delete_texture(gm->img.cloth);
	mlx_delete_texture(gm->img.hair);
	mlx_delete_image(gm->mlx, gm->img.py_img);
	mlx_delete_image(gm->mlx, gm->img.cloth_img);
	mlx_delete_image(gm->mlx, gm->img.hair_img);
	gm->img.py = mlx_load_png("./imagen/player_u.png");
	gm->img.hair = mlx_load_png("./imagen/hair_u.png");
	gm->img.cloth = mlx_load_png("./imagen/cloth_u.png");
	gm->img.py_img = mlx_texture_to_image(gm->mlx, gm->img.py);
	gm->img.hair_img = mlx_texture_to_image(gm->mlx, gm->img.hair);
	gm->img.cloth_img = mlx_texture_to_image(gm->mlx, gm->img.cloth);
}

void	p_to_down(t_game *gm)
{
	mlx_delete_texture(gm->img.py);
	mlx_delete_texture(gm->img.cloth);
	mlx_delete_texture(gm->img.hair);
	mlx_delete_image(gm->mlx, gm->img.py_img);
	mlx_delete_image(gm->mlx, gm->img.cloth_img);
	mlx_delete_image(gm->mlx, gm->img.hair_img);
	gm->img.py = mlx_load_png("./imagen/player.png");
	gm->img.hair = mlx_load_png("./imagen/hair.png");
	gm->img.cloth = mlx_load_png("./imagen/cloth.png");
	gm->img.py_img = mlx_texture_to_image(gm->mlx, gm->img.py);
	gm->img.hair_img = mlx_texture_to_image(gm->mlx, gm->img.hair);
	gm->img.cloth_img = mlx_texture_to_image(gm->mlx, gm->img.cloth);
}
