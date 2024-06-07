/* ************************************************************************** */
/*                                                                            */
//*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:43:55 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/07 21:43:13 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
int main()
{
	char *p = "lol";
	int	n = ft_printf("%p", p);
	printf("\n%d\n", n);
	n = printf("%p", p);
	printf("\n%d", n);
}
