/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:30:34 by gufortel          #+#    #+#             */
/*   Updated: 2018/07/10 01:11:10 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	i = 0;
	if (s1 && s2)
	{
		str = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!str)
			return (NULL);
		while (*s1)
		{
			str[i++] = *s1;
			s1++;
		}
		while (*s2)
		{
			str[i++] = *s2;
			s2++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
