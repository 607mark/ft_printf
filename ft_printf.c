/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:17:33 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/02 19:57:25 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_f(const char **specifier, va_list args, int *printed)
{
	if (**specifier == 'c')
		*printed += write(1, &(char){(char)va_arg(args, int)}, 1);
	if (**specifier == 's')
		*printed += printf("%s", va_arg(args, char *));
	if (**specifier == 'p')
		*printed += printf("%p", va_arg(args, void *));
	if (**specifier == 'd' || **specifier == 'i')
		*printed += printf("%d", va_arg(args, int));
	if (**specifier == 'u')
		*printed += printf("%u", va_arg(args, unsigned int));
	if (**specifier == 'x')
		*printed += printf("%x", va_arg(args, unsigned int));
	if (**specifier == 'X')
		*printed += printf("%X", va_arg(args, unsigned int));
	if (**specifier == '%')
		*printed += write(1, "%", 1);
	*specifier += *printed;
	return (1);
}

int ft_printf(const char *s, ...)
{
	va_list args;
	int printed;
	const char formats[10] = "cspdiuxX%";
	
	va_start(args, s);
	printed = 0;
	while (*s)
	{
		if (ft_strchr(s, '%'))
		{
			printed += putstr(s, ft_strchr(s, '%') - s);
			s = ft_strchr(s, '%') + 1;
			if (ft_strchr(formats, *s) && (print_f(&s, args, &printed) == -1))
				return (-1);
			else 
				s++;
		}
		else
		{
			printed += putstr(s, -1);
			break;
		}
	}
	return (printed);
}
