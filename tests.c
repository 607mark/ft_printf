/* ************************************************************************** */
/*                                                                            */
//*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:43:55 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/02 19:12:07 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
/*
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
	printf("sum %d\n", sum(4, 1000,10,  2, 3));
}
*/

#include <stdio.h>
/*
int main() {
    int num = 499992;

    // Without any flags
    printf("Without flags: '%d'\n", num);

    // With field minimum width
    printf("With field width 5: '%5d'\n", num);

    // With zero-fill
    printf("With zero-fill 5: '%05d'\n", num);

    // With left-justify
    printf("With left-justify 5: '%-5d'\n", num);

    // With both zero-fill and left-justify
    printf("With zero-fill and left-justify 5: '%-05d'\n", num);

    return 0;
}
*/

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
int main()
{
	int n = ft_printf("lol%d", 9);
	printf("\n%d", n);
}
