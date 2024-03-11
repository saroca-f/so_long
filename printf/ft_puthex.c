/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:46:26 by saroca-f          #+#    #+#             */
/*   Updated: 2023/12/15 11:57:32 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(unsigned long long hexa, char *str)
{
	int	len;

	len = 0;
	if (hexa > 15)
	{
		len += ft_putp(hexa / 16, str);
	}
	write (1, &str[hexa % 16], 1);
	len++;
	return (len);
}

int	ft_puthex(void *arg)
{
	unsigned long long		hexa;
	int						len;
	char					*str;

	len = 0;
	str = "0123456789abcdef";
	hexa = (unsigned long long)arg;
	len += ft_puts("0x");
	len += ft_putp(hexa, str);
	return (len);
}
