/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:09:12 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/04 14:38:43 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putstr(char *s);
size_t	ft_printf_strlen(const char *str);
int		ft_printf(char const *str, ...);
int		ft_type_detector(char const str, va_list args);
int		ft_putp(unsigned long long hexa, char *str);
int		ft_puthex(void *arg);
int		ft_puts(char *t);
int		ft_putchar(int c);
int		ft_putx(unsigned int x, char str);

#endif