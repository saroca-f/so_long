/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:16:24 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/04 15:22:21 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_map_elements(t_lst *line, int size)
{
	int			i;
	int			j;
	t_lst		*ret;

	i = 1;
	ret = line;
	while (i++ <= size)
	{
		j = 0;
		while (ret->line[j] != '\0' && ret->line[j] != '\n')
		{
			if (ret->line[j] != '1' && ret->line[j] != '0'
				&& ret->line[j] != 'P' && ret->line[j] != 'C'
				&& ret->line[j] != 'E' && ret->line[j] != 'X')
				return (false);
			j++;
		}
		ret = ret->next;
	}
	return (true);
}
