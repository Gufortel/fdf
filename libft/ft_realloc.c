/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 02:35:14 by gufortel          #+#    #+#             */
/*   Updated: 2018/07/10 03:13:23 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	char	*str;

	if (!ptr)
	{
		str = ft_memalloc(size);
		ft_memdel(&ptr);
		return (str);
	}
	if (!size && ptr)
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	str = ft_memalloc(size);
	ft_memcpy(str, ptr, size);
	ft_memdel(&ptr);
	return (str);
}
