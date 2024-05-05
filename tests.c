/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:43:55 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/05 18:58:57 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int count, ...)
{
	va_list args;
	va_start(args, count);
	int i;
	int n;
	int s;

	i = 0;
	s = 0;
	while (i < count)
	{
		n = va_arg(args, int);
		i++;
		s +=n;
	}
	va_end(args);
	return s;
}

int main()
{
	printf("sum %d\n", sum(4, 1, 2, 3));
}
