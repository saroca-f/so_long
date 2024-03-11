/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:37:27 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 19:13:57 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_map_elements(t_lst **lst)
{
	write (1, "Error\n", 6);
	write (1, "This map is not correct\n", 25);
	free_lst(lst);
	exit(1);
}

void	error_map_size(t_lst **lst)
{
	write (1, "Error\n", 6);
	write (1, "This map is not a rectangle\n", 29);
	free_lst(lst);
	exit(1);
}

void	error_map_borders(t_lst **lst)
{
	write (1, "Error\n", 6);
	write (1, "This map is not bordered\n", 26);
	free_lst(lst);
	exit(1);
}

void	error_pasable(t_lst **lst, char **map)
{
	write (1, "Error\n", 6);
	write (1, "This map is not pasable\n", 25);
	free_lst(lst);
	free_mat(map);
	exit(1);
}

void	error_imagen(t_game *gm)
{
	write (1, "Error\n", 6);
	ft_printf("Cannot found imagen\n");
	mlx_terminate(gm->mlx);
	free_mat(gm->map);
	exit(1);
}
