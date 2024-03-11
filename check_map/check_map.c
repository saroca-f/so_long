/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:24:29 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 16:36:45 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_coord	*looking_for_p(t_lst *tline, int size)
{
	t_coord	*p;
	t_lst	*ret;
	int		i;
	int		j;

	i = 1;
	ret = tline;
	p = malloc(sizeof(t_coord));
	while (i <= size)
	{
		j = 0;
		while (ret->line[j] != '\0' && ret->line[j] != '\n')
		{
			if (ret->line[j] == 'P')
			{
				p->li = i - 1;
				p->cl = j;
				return (p);
			}
			j++;
		}
		ret = ret->next;
		i++;
	}
	return (free (p), NULL);
}

bool	check_pasable(t_lst *tline, int size, char **map, size_t str_size)
{
	t_coord		*p;
	t_coord		*map_size;
	t_counter	*count;

	p = looking_for_p(tline, size);
	if (!p)
		return (false);
	count = elements_counter(tline, size);
	if (count->collect == 0 || count->exit != 1 || count->heroe != 1)
		return (free (count), false);
	map_size = malloc(sizeof(t_coord));
	if (!map_size)
		return (false);
	map_size->cl = str_size;
	map_size->li = size - 1;
	if (!pass_cont(p, count, map, map_size))
		return (free (map_size), false);
	free (map_size);
	return (true);
}

bool	check_map_size(t_lst *line, int n)
{
	int		i;
	t_lst	*ret;
	size_t	size;

	i = 1;
	ret = line;
	size = ft_strlen(line->line);
	while (i <= n)
	{
		if (ft_strlen(ret->line) != size && i < n)
			return (false);
		if (ft_strlen(ret->line) != (size - 1) && i == n)
			return (false);
		ret = ret->next;
		i++;
	}
	return (true);
}

bool	check_map_borders(t_lst *line, size_t size, size_t str_size)
{
	t_lst	*ret;
	size_t	i;
	int		j;

	ret = line;
	i = 1;
	while (i <= size)
	{
		j = 0;
		if (i == 1 || i == size)
		{
			while (ret->line[j] && ret->line[j] != '\n')
			{
				if (ret->line[j] != '1')
					return (false);
				j++;
			}
		}
		else
			if (ret->line[0] != '1' || ret->line[str_size] != '1')
				return (false);
		ret = ret->next;
		i++;
	}
	return (true);
}

void	check_map(t_lst **tline, int size, char **mat_map)
{
	size_t	str_size;

	str_size = ft_strlen2((*tline)->line) - 1;
	if (!check_map_elements(*tline, size))
		error_map_elements(tline);
	if (!check_map_size(*tline, size))
		error_map_size(tline);
	if (!check_map_borders(*tline, size, str_size))
		error_map_borders(tline);
	if (!check_pasable(*tline, size, mat_map, str_size))
		error_pasable(tline, mat_map);
}
