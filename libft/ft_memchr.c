/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 02:43:46 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/10 01:29:57 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	size_t				i;

	str = (unsigned const char*)s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return ((void*)str);
		str++;
		i++;
	}
	return (NULL);
}
