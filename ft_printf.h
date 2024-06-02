/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:18:19 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/02 18:52:29 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

char	*ft_strchr(const char *s, int c);
int	ft_toupper(int c);
size_t	ft_strlen(const char *s);
int putstr(const char *s, int len);
int ft_printf(const char *s, ...);
int print_f(const char **specifier, va_list args, int *printed);
#endif
