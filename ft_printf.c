/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:17:33 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/30 21:06:42 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_f(char **specifier, va_list args, int *printed)
{

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
			if (*(ft_strchr(s, '%') + 1))
				s = ft_strchr(s, '%') + 1;
			if (ft_strchr(formats, *s) && (print_f(&s, args, &printed) == -1));
				return (-1);
			else 
				s++;
		}
		else
			printed += putstr(s, -1);
		s++;
	}
	return (printed);
}
