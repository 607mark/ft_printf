/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:48:56 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/07 21:41:44 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int put_ptr(unsigned long ptr)
{
	int ret_value;
	char *radix = "0123456789abcdef";
	ret_value = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	ret_value += 2;
	if (!ptr)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return(ret_value + 1);
	}
	ret_value += put_hex(ptr / 16, 'x');
	if (write(1, (radix + ptr % 16), 1) == -1)
		return (-1);
	ret_value++;
	return (ret_value);
}

int put_hex(long long num, char c)
{
	int	shift;
	int leading_zero;
	int ret_value;
	int digit;
	char *radix = "0123456789abcdef";
	
	ret_value = 0;
	if (num == 0)
		return (write (1, "0", 1));
    shift = sizeof(long long) * 8 - 4;
	leading_zero = 1;
	if (num < 0)
	{
		if (write(1, "-", 1 == -1))
			return (-1);
		num = -num;
	}
	while (shift >= 0)
	{
		digit = (num >> shift) & 0xF;
		if (digit != 0 || !leading_zero)
		{
			if (write(1, (radix + digit), 1) == -1)
					return (-1);
			ret_value++;
			leading_zero = 0;
		}
		shift -= 4;
	}
	return (ret_value);
}

int put_int(long long n)
{
	return (1);
}
