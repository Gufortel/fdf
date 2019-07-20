/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 05:28:11 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/10 05:12:22 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;

	if (*to_find == '\0')
		return ((char*)str);
	i = 0;
	while (*str && len)
	{
		if (*str == to_find[i])
			i++;
		else
			i = 0;
		if (to_find[i] == '\0')
			return ((char*)(str - i + 1));
		str++;
		len--;
	}
	return (NULL);
}
