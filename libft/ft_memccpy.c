/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 01:06:50 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/10 00:59:18 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	unsigned const char		*st;
	unsigned char			*str;
	size_t					i;

	st = (unsigned const char*)src;
	str = (unsigned char*)dest;
	i = 0;
	while (i < size)
	{
		str[i] = st[i];
		if (st[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
