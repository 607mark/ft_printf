/* ************************************************************************** */
/*                                                                            */
//*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:43:55 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/07 18:29:10 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
int main()
{
	char *p = 0;
	int	n = ft_printf("%s%s%s%s", p, p, p, p);
	printf("%d", n);
}
