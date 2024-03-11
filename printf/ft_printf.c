/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:10 by saroca-f          #+#    #+#             */
/*   Updated: 2023/12/14 18:38:25 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		count;
	int		len;
	va_list	args;

	va_start(args, str);
	if (write(1, "", 0) == -1)
		return (-1);
	count = 0;
	len = 0;
	while (str[count])
	{
		if (str[count] == '%')
		{
			len += ft_type_detector(str[count + 1], args);
			count++;
		}
		else
			len += ft_putchar(str[count]);
		count++;
	}
	va_end(args);
	if (count < 0)
		return (-1);
	return (len);
}

/*int	main(void)
{
	printf("cuenta: %d\n", printf("imprime: %x ", 10000));
	printf("cuenta: %d\n", ft_printf("imprime: %x ", 10000));
	return (0);
}
*/