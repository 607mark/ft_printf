/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:49:26 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/20 17:17:26 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	put_str(const char *s, int len, int *printed)
{
	int	tmp;

	tmp = 0;
	if (!s)
	{
		tmp = ((write(1, "(null)", 6)));
		*printed += tmp;
		return (tmp);
	}
	if (len == -1)
		len = ft_strlen(s);
	tmp = (write (1, s, len));
	if (tmp == -1)
		*printed = -1;
	else
		*printed += tmp;
	return (tmp);
}
