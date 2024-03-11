/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:21:27 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 18:28:34 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_to_right(t_game *game)
{
	int	i;
	int	j;

	j = game->n.li;
	i = game->n.cl + 1;
	if (game->map[j][i] == '0')
		void_case(j, i, game);
	if (game->map[j][i] == 'C')
		c_case(j, i, game);
	if (game->map[j][i] == 'E')
		e_case(j, i, game);
	if (game->map[j][i] == 'X')
		x_case(game);
	if (game->map[j][i] == '1')
		person_print(game->n.li, game->n.cl, game);
	if (game->map[j][i] != '1')
	{
		game->n.cl = i;
		game->moves = game->moves + 1;
		mlx_image_to_window(game->mlx, game->img.fl_img, 0, 0);
		mlx_image_to_window(game->mlx, game->img.wall_img, 0, 0);
		put_counter(game);
		ft_printf("%d\n", game->moves);
	}
}

void	move_to_left(t_game *game)
{
	int	i;
	int	j;

	j = game->n.li;
	i = game->n.cl - 1;
	if (game->map[j][i] == '0')
		void_case(j, i, game);
	if (game->map[j][i] == 'C')
		c_case(j, i, game);
	if (game->map[j][i] == 'E')
		e_case(j, i, game);
	if (game->map[j][i] == 'X')
		x_case(game);
	if (game->map[j][i] == '1')
		person_print(game->n.li, game->n.cl, game);
	if (game->map[j][i] != '1')
	{
		game->n.cl = i;
		game->moves = game->moves + 1;
		mlx_image_to_window(game->mlx, game->img.fl_img, 0, 0);
		mlx_image_to_window(game->mlx, game->img.wall_img, 0, 0);
		put_counter(game);
		ft_printf("%d\n", game->moves);
	}
}

void	move_to_up(t_game *game)
{
	int	i;
	int	j;

	j = game->n.li - 1;
	i = game->n.cl;
	if (game->map[j][i] == '0')
		void_case(j, i, game);
	if (game->map[j][i] == 'C')
		c_case(j, i, game);
	if (game->map[j][i] == 'E')
		e_case(j, i, game);
	if (game->map[j][i] == 'X')
		x_case(game);
	if (game->map[j][i] == '1')
		person_print(game->n.li, game->n.cl, game);
	if (game->map[j][i] != '1')
	{
		game->n.li = j;
		game->moves = game->moves + 1;
		mlx_image_to_window(game->mlx, game->img.fl_img, 0, 0);
		mlx_image_to_window(game->mlx, game->img.wall_img, 0, 0);
		put_counter(game);
		ft_printf("%d\n", game->moves);
	}
}

void	move_to_down(t_game *game)
{
	int	i;
	int	j;

	j = game->n.li + 1;
	i = game->n.cl;
	if (game->map[j][i] == '0')
		void_case(j, i, game);
	if (game->map[j][i] == 'C')
		c_case(j, i, game);
	if (game->map[j][i] == 'E')
		e_case(j, i, game);
	if (game->map[j][i] == 'X')
		x_case(game);
	if (game->map[j][i] == '1')
		person_print(game->n.li, game->n.cl, game);
	if (game->map[j][i] != '1')
	{
		game->n.li = j;
		game->moves = game->moves + 1;
		mlx_image_to_window(game->mlx, game->img.fl_img, 0, 0);
		mlx_image_to_window(game->mlx, game->img.wall_img, 0, 0);
		put_counter(game);
		ft_printf("%d\n", game->moves);
	}
}

void	ft_key(struct mlx_key_data key_data, void *param)
{
	t_game		*game;

	game = param;
	if (key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (key_data.key == MLX_KEY_D && key_data.action == MLX_RELEASE)
	{
		p_to_right(game);
		move_to_right(game);
	}
	if (key_data.key == MLX_KEY_A && key_data.action == MLX_RELEASE)
	{
		p_to_left(game);
		move_to_left(game);
	}
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_RELEASE)
	{
		p_to_up(game);
		move_to_up(game);
	}
	if (key_data.key == MLX_KEY_S && key_data.action == MLX_RELEASE)
	{
		p_to_down(game);
		move_to_down(game);
	}
}
