/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:26:04 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/04 17:37:13 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	sizeint(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sizen;
	int		nret;

	nret = n;
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	sizen = sizeint(n);
	str = malloc(sizeof(char) * (sizen + 1));
	if (!str)
		return (NULL);
	str[sizen] = '\0';
	if (n < 0)
		n = -n;
	while (sizen > 0)
	{
		str[sizen - 1] = (n % 10) + '0';
		n = n / 10;
		sizen--;
	}
	if (nret < 0)
		str[0] = '-';
	return (str);
}
