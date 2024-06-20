/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:17:33 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/20 19:45:00 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	print_f(const char **specifier, va_list args, int *printed)
{
	int	len;

	len = 0;
	if (**specifier == 'c')
		len = write(1, &(char){(char)va_arg(args, int)}, 1);
	else if (**specifier == 's')
		put_str(va_arg(args, char *), -1, &len);
	else if (**specifier == 'p')
		len = put_ptr((unsigned long)va_arg(args, void *));
	else if (**specifier == 'd' || **specifier == 'i')
		len = put_int(va_arg(args, int));
	else if (**specifier == 'u')
		len = put_int(va_arg(args, unsigned int));
	else if (**specifier == 'x' || **specifier == 'X')
		len = put_hex(va_arg(args, unsigned int), **specifier);
	else if (**specifier == '%')
		len = write(1, "%", 1);
	else
		len = 0;
	if (len < 0)
		return (-1);
	(*specifier)++;
	*printed += len;
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		printed;
	int		tmp;

	va_start(args, s);
	printed = 0;
	while (*s && printed != -1)
	{
		tmp = 0;
		if (ft_strchr(s, '%'))
		{
			if (put_str(s, ft_strchr(s, '%') - s, &printed) == -1)
				break ;
			s = ft_strchr(s, '%') + 1;
			print_f(&s, args, &printed);
		}
		else
		{
			tmp = put_str(s, -1, &printed);
			if (tmp != -1)
				s += tmp;
		}
	}
	va_end(args);
	return (printed);
}
