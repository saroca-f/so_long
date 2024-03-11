/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:32:22 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/26 12:01:35 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_free(char **strs, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

int	cwords(char const *s, char c)
{
	int	times;
	int	is_true;

	is_true = 0;
	times = 0;
	while (*s)
	{
		if (*s != c && is_true == 0)
		{
			times++;
			is_true = 1;
		}
		else if (*s == c)
			is_true = 0;
		s++;
	}
	return (times);
}

static char	**ft_while(char const *s, char c, char **st, char const *s0)
{
	int		wordcont;
	size_t	i;
	size_t	j;

	wordcont = -1;
	i = 0;
	st[0] = (char *)s0;
	j = 1;
	while (i <= ft_strlen2(s))
	{
		if (s[i] != c && wordcont < 0)
			wordcont = i;
		else if ((s[i] == c || i == ft_strlen2(s)) && wordcont >= 0)
		{
			st[j] = ft_substr(s, wordcont, (i - wordcont));
			if (!st[j])
				return (ft_free(st, j));
			wordcont = -1;
			j++;
		}
		i++;
	}
	st[j] = NULL;
	return (st);
}

char	**ft_split(char const *s, char c, char const *s0)
{
	char	**st;

	if ((s[0] == ' ' && s[1] == '\0') || s[0] == '\0')
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	st = malloc((cwords(s, c) + 2) * sizeof(char *));
	if (!st)
		return (NULL);
	st = ft_while(s, c, st, s0);
	return (st);
}
