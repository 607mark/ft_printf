/* ************************************************************************** */
/*                                                                            */
//*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:43:55 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/07 17:20:38 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
int main()
{
	char *p = "hello";

	int n = printf("%p\n", p);
	n = ft_printf("%p\n", p);
}
