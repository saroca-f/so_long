/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:47:27 by saroca-f          #+#    #+#             */
/*   Updated: 2023/12/15 10:33:37 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putx(unsigned int x, char str)
{
	int		len;

	len = 0;
	if (x > 15)
	{
		len += ft_putx(x / 16, str);
		len += ft_putx(x % 16, str);
	}
	if (x <= 15)
	{
		if (x < 10)
			len += ft_putchar(x + '0');
		else if (x >= 10)
		{
			if (str == 'x')
				len += ft_putchar((x - 10) + 'a');
			else if (str == 'X')
				len += ft_putchar((x - 10) + 'A');
		}
	}
	return (len);
}

int	ft_putchar(int c)
{
	return (write (1, &c, 1));
}
