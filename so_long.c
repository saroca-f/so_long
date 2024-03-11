/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:42:52 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 13:17:59 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	format_control(char *name)
{
	char	*s;
	int		i;
	int		j;

	s = ".ber";
	j = 0;
	i = ft_strlen(name) - 4;
	while (name[i + j] != '\0')
	{
		if (name[i + j] != s[j])
		{
			ft_printf ("Error\nFormat not correct\n");
			exit (1);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		size;
	t_lst	*map;
	char	**mat_map;

	if (argc != 2)
	{
		printf ("Error\nArguments error\n");
		exit (1);
	}
	format_control (argv[1]);
	do_map (&map, argv[1]);
	size = ft_lstsize(map);
	mat_map = mat_constructor(map, size);
	check_map(&map, size, mat_map);
	free_mat(mat_map);
	mat_map = mat_constructor(map, size);
	game_start(mat_map);
	free_mat(mat_map);
	free_lst(&map);
}
