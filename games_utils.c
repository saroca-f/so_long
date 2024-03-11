/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:21:27 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 17:15:05 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_right(t_game *game, t_coord pos)
{
	int	i;
	int	j;

	j = pos.li;
	i = pos.cl + 1;
	if (game->map[j][i] == '0')
		void_case(j, i, game);
	if (game->map[j][i] == 'C')
		c_case(j, i, game);
	if (game->map[j][i] == 'E')
		e_case(j, i, game);
	if (game->map[j][i] != '1')
	{
		game->n.cl = i;
		game->moves = game->moves + 1;
		ft_printf("%d\n", game->moves);
	}
}

void	move_to_left(t_game *game, t_coord pos)
{
	int	i;
	int	j;

	j = pos.li;
	i = pos.cl - 1;
	if (game->map[j][i] == '0')
		void_case(j, i, game);
	if (game->map[j][i] == 'C')
		c_case(j, i, game);
	if (game->map[j][i] == 'E')
		e_case(j, i, game);
	if (game->map[j][i] != '1')
	{
		game->n.cl = i;
		game->moves = game->moves + 1;
		ft_printf("%d\n", game->moves);
	}
}

void	move_to_up(t_game *game, t_coord pos)
{
	int	i;
	int	j;

	j = pos.li - 1;
	i = pos.cl;
	if (game->map[j][i] == '0')
		void_case(j, i, game);
	if (game->map[j][i] == 'C')
		c_case(j, i, game);
	if (game->map[j][i] == 'E')
		e_case(j, i, game);
	if (game->map[j][i] != '1')
	{
		game->n.li = j;
		game->moves = game->moves + 1;
		ft_printf("%d\n", game->moves);
	}
}

void	move_to_down(t_game *game, t_coord pos)
{
	int	i;
	int	j;

	j = pos.li + 1;
	i = pos.cl;
	if (game->map[j][i] == '0')
		void_case(j, i, game);
	if (game->map[j][i] == 'C')
		c_case(j, i, game);
	if (game->map[j][i] == 'E')
		e_case(j, i, game);
	if (game->map[j][i] != '1')
	{
		game->n.li = j;
		game->moves = game->moves + 1;
		ft_printf("%d\n", game->moves);
	}
}

void	ft_key(struct mlx_key_data key_data, void *param)
{
	t_game		*game;
	t_coord		old_pos;

	game = param;
	old_pos = game->n;
	if (key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (key_data.key == MLX_KEY_D && key_data.action == MLX_RELEASE)
		move_to_right(game, old_pos);
	if (key_data.key == MLX_KEY_A && key_data.action == MLX_RELEASE)
		move_to_left(game, old_pos);
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_RELEASE)
		move_to_up(game, old_pos);
	if (key_data.key == MLX_KEY_S && key_data.action == MLX_RELEASE)
		move_to_down(game, old_pos);
}
