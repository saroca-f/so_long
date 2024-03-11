/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:16:36 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 16:36:20 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	t_count_init(t_counter	*c)
{
	c->exit = 0;
	c->heroe = 0;
	c->collect = 0;
}

t_counter	*elements_counter(t_lst *line, int size)
{
	int			i;
	int			j;
	t_lst		*ret;
	t_counter	*c;

	i = 1;
	ret = line;
	c = malloc (sizeof(t_counter));
	t_count_init(c);
	while (i++ <= size)
	{
		j = 0;
		while (ret->line[j] != '\0' && ret->line[j] != '\n')
		{
			if (ret->line[j] == 'C')
				c->collect = c->collect + 1;
			if (ret->line[j] == 'P')
				c->heroe = c->heroe + 1;
			if (ret->line[j] == 'E')
				c->exit = c->exit + 1;
			j++;
		}
		ret = ret->next;
	}
	return (c);
}

void	fill(char **tab, t_coord size, t_coord cur, t_counter *real)
{
	if (cur.li < 0 || cur.li >= size.li || cur.cl < 0
		|| cur.cl >= size.cl || tab[cur.li][cur.cl] == 'X'
		|| tab[cur.li][cur.cl] == '1')
		return ;
	if (tab[cur.li][cur.cl] == 'E')
		real->exit = real->exit + 1;
	if (tab[cur.li][cur.cl] == 'C')
		real->collect = real->collect + 1;
	if (tab[cur.li][cur.cl] == 'P')
		real->heroe = real->heroe + 1;
	tab[cur.li][cur.cl] = 'X';
	fill(tab, size, (t_coord){cur.li - 1, cur.cl}, real);
	fill(tab, size, (t_coord){cur.li + 1, cur.cl}, real);
	fill(tab, size, (t_coord){cur.li, cur.cl - 1}, real);
	fill(tab, size, (t_coord){cur.li, cur.cl + 1}, real);
}

t_counter	*flood_fill(char **tab, t_coord size, t_coord cur)
{
	t_counter	*real;

	real = malloc (sizeof(t_counter));
	if (!real)
		return (NULL);
	t_count_init(real);
	fill(tab, size, cur, real);
	return (real);
}

bool	pass_cont(t_coord *p, t_counter *count, char **map, t_coord *size)
{
	t_counter	*real;

	real = flood_fill(map, *size, *p);
	free (p);
	free (count);
	if (count->collect != real->collect || count->exit != real->exit
		|| count->heroe != real->heroe)
		return (free (real), false);
	return (free (real), true);
}
