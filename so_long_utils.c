/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:37:10 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 18:53:20 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lstsize(t_lst *lst)
{
	int	cont;

	cont = 0;
	while (lst)
	{
		lst = lst->next;
		cont++;
	}
	return (cont);
}

void	ft_lstadd_back(t_lst **alst, t_lst *new)
{
	t_lst	*temporal;

	temporal = (*alst);
	if ((*alst))
	{
		while (temporal->next != NULL)
			temporal = temporal->next;
		temporal->next = new;
	}
	if (!(*alst))
		((*alst) = new);
}

t_lst	*ft_lstnew(char *content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	if (new)
	{
		new->line = content;
		new->next = NULL;
	}
	return (new);
}

void	do_map(t_lst **map, char *argv)
{
	t_lst	*new_line;
	char	*map_line;
	int		fd;
	int		cont;

	cont = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile do not exist\n");
		exit (1);
	}
	map_line = get_next_line(fd);
	while (map_line[cont])
		cont++;
	while (map_line)
	{
		new_line = ft_lstnew(map_line);
		ft_lstadd_back(map, new_line);
		map_line = get_next_line(fd);
	}
}

int	line_size(int fd)
{
	char	*line;
	int		i;

	if (!fd)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		free (line);
		i++;
	}
	return (i);
}
