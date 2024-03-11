/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:02:37 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/23 14:27:41 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*static_maker(char *static_str, int fd)
{
	char	*buffer;
	int		cread;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	cread = 1;
	while (cread != 0 && !ft_strchr(static_str, '\n'))
	{
		cread = read(fd, buffer, BUFFER_SIZE);
		if (cread == -1)
		{
			free(buffer);
			free(static_str);
			return (NULL);
		}
		buffer[cread] = '\0';
		static_str = ft_strjoin(static_str, buffer);
	}
	free(buffer);
	return (static_str);
}

char	*make_line(char *static_str, int i)
{
	char	*str;

	if (!static_str[i])
		return (NULL);
	while (static_str[i] && static_str[i] != '\n')
		i++;
	if (static_str[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (static_str[i] && static_str[i] != '\n')
	{
		str[i] = static_str[i];
		i++;
	}
	if (static_str[i] == '\n')
	{
		str[i] = static_str[i];
		i++;
	}
	return (str[i] = '\0', str);
}

char	*new_static_maker(char *static_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = static_str;
	while (static_str[i] && (static_str[i] != '\n'))
		i++;
	if (static_str[i] == '\0')
	{
		free(static_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(static_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (static_str[i])
		str[j++] = static_str[i++];
	str[j] = '\0';
	free (static_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*static_str;
	int				i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_str = static_maker(static_str, fd);
	if (!static_str)
	{
		free(static_str);
		return (NULL);
	}
	line = make_line(static_str, i);
	static_str = new_static_maker(static_str);
	return (line);
}
