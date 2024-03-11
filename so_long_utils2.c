/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:48:15 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/27 17:17:23 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**mat_constructor(t_lst *map, int size)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		ret[i] = ft_strdup(map->line);
		map = map->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	free_lst(t_lst **map)
{
	t_lst	*ret;

	ret = *map;
	while (*map)
	{
		ret = *map;
		free(ret->line);
		*map = ret->next;
		free (ret);
	}
}

void	free_mat(char **mat)
{
	int	j;

	j = 0;
	while (mat[j])
	{
		free(mat[j]);
		j++;
	}
	free (mat);
}
