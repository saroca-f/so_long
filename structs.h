/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:38:30 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 17:51:09 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

typedef struct s_coord
{
	int		li;
	int		cl;
}	t_coord;

typedef struct s_texture
{
	mlx_texture_t		*wall;
	mlx_texture_t		*floor;
	mlx_texture_t		*col;
	mlx_texture_t		*py;
	mlx_texture_t		*cloth;
	mlx_texture_t		*hair;
	mlx_texture_t		*exit;
	mlx_texture_t		*enemy;
	mlx_image_t			*wall_img;
	mlx_image_t			*fl_img;
	mlx_image_t			*col_img;
	mlx_image_t			*py_img;
	mlx_image_t			*cloth_img;
	mlx_image_t			*hair_img;
	mlx_image_t			*e_img;
	mlx_image_t			*en_img;
}	t_texture;

typedef struct s_game
{
	mlx_t		*mlx;
	t_coord		size;
	t_coord		n;
	t_coord		e;
	char		**map;
	int			collect;
	int			total_collect;
	t_texture	img;
	int			moves;
	bool		c_exit;
}	t_game;

typedef struct s_key_event
{
	int	keycode;
}	t_key_event;