/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 04:51:28 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/09 04:11:59 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			sr;
	unsigned int	i;
	int				j;
	size_t			de;

	sr = 0;
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	de = i;
	while (i + 1 < size && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[sr])
		sr++;
	if (de > size)
		de = size;
	return ((unsigned int)(de + sr));
}
