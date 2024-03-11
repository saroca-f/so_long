/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_detector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:20:27 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/04 14:40:29 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puts(char *t)
{
	if (t == NULL)
		t = "(null)";
	ft_putstr(t);
	return (ft_printf_strlen(t));
}

int	ft_putd(int d)
{
	int		count;

	count = 0;
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (d < 0)
	{
		count += ft_putchar('-');
		count += ft_putd(-d);
	}
	else if (d >= 10)
	{
		count += ft_putd(d / 10);
		count += ft_putd(d % 10);
	}
	else
		count += ft_putchar(d + '0');
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_putnbr(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
	count++;
	return (count);
}

int	ft_type_detector(char const str, va_list args)
{
	if (str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str == 's')
		return (ft_puts(va_arg(args, char *)));
	else if (str == 'p')
		return (ft_puthex(va_arg(args, void *)));
	else if (str == 'd')
		return (ft_putd(va_arg(args, int)));
	else if (str == 'i')
		return (ft_putd(va_arg(args, int)));
	else if (str == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (str == 'x' || str == 'X')
		return (ft_putx(va_arg(args, unsigned int), str));
	else if (str == '%')
		return (ft_putchar(str));
	return (0);
}
