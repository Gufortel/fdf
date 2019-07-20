/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:28:57 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/10 00:39:01 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*str;
	char		*sttr;
	size_t		i;

	str = (const char*)src;
	sttr = (char*)dest;
	i = 0;
	while (i < n)
	{
		sttr[i] = str[i];
		i++;
	}
	return (dest);
}
