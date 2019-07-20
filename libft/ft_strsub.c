/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:16:30 by gufortel          #+#    #+#             */
/*   Updated: 2018/10/28 23:51:23 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char*)ft_memalloc(sizeof(char) * len + 10);
	i = 0;
	if (!str)
		return (str);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	if (s[start] != '\0')
		str[i] = '\0';
	else
		str[i] = s[start];
	return (str);
}
