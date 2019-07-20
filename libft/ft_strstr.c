/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 04:53:37 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/09 23:36:17 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		adr;

	i = 0;
	j = 0;
	adr = 0;
	if (!(to_find[0]))
		return ((char*)str);
	while (str[i])
	{
		j = i;
		adr = 0;
		while (str[j] == to_find[adr])
		{
			j++;
			adr++;
			if (!(to_find[adr]))
				return ((char*)str + i);
		}
		i++;
	}
	return (0);
}
