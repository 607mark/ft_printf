/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:17:33 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/08 19:03:03 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_f(const char **specifier, va_list args, int *printed)
{
	int	len;

	len = 0;
	if (**specifier == 'c')
		len += write(1, &(char){(char)va_arg(args, int)}, 1);
	else if (**specifier == 's')
		len += put_str(va_arg(args, char *), -1);
	else if (**specifier == 'p')
		len += put_ptr((unsigned long)va_arg(args, void *));
	else if (**specifier == 'd' || **specifier == 'i')
		len += put_int(va_arg(args, int));
	else if (**specifier == 'u')
		len += printf("%u", va_arg(args, unsigned int));
	else if (**specifier == 'x' || **specifier == 'X')
		len += put_hex(va_arg(args, unsigned int), **specifier);
	else if (**specifier == '%')
		len += write(1, "%", 1);
	else
		return (-1);

	if (len < 0)
		return (-1);
	*printed += len;
	(*specifier)++;
	return (1);
}

int ft_printf(const char *s, ...)
{
    va_list args;
    int printed;
    char *next_format;

    va_start(args, s);
    printed = 0;
    while (*s)
    {
        next_format = ft_strchr(s, '%');
        if (next_format)
        {
            printed += put_str(s, next_format - s);
            s = next_format + 1;
            if (ft_strchr(FORMAT_SET, *s))
				print_f(&s, args, &printed);
        }
        else
        {
            printed += put_str(s, -1);
            break;
        }
    }
    va_end(args);
    return (printed);
}
