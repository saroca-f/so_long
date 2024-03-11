/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:43:41 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/23 14:42:16 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen2(const char *str)
{
	size_t	cont;

	cont = 0;
	while (str[cont] != '\0' && str[cont] != '\n')
	{
		cont++;
	}
	return (cont);
}

char	*ft_strdup(const char *s1)
{
	size_t		len;
	char		*s2;
	char		*s3;

	len = 0;
	while (s1[len])
		len++;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	s3 = s2;
	while (*s1)
		*s3++ = *s1++;
	*s3 = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*s2;

	if (!s)
		return (NULL);
	if (start > ft_strlen2(s))
		return (ft_strdup(""));
	if (len > ft_strlen2(s + start))
		len = ft_strlen2(s + start);
	s1 = malloc(len + 1);
	if (!s1)
		return (NULL);
	s2 = s1;
	while (len--)
	{
		*s2 = s[start];
		s2++;
		start++;
	}
	*s2 = '\0';
	return (s1);
}
