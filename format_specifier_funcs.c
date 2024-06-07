/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:48:56 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/07 17:44:22 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int put_ptr(unsigned long ptr)
{
	int ret_value;

	ret_value = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	ret_value += 2;
	ret_value += put_hex(ptr, 'x');
	return (ret_value);
}

int put_hex(unsigned long n, char c)
{
}
