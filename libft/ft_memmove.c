/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 02:07:12 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/10 06:06:35 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*str;
	char		*st;
	size_t		i;

	str = (const char*)src;
	st = (char*)dest;
	i = 0;
	if ((char*)str < st)
	{
		while (n--)
			st[n] = str[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
