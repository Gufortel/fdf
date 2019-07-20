/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:58:11 by gufortel          #+#    #+#             */
/*   Updated: 2018/10/29 18:18:26 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*str;
	size_t	i;

	i = 0;
	mem = malloc(size * 2);
	str = (char*)mem;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (mem);
}
