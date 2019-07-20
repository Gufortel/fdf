/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 05:20:37 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/10 02:10:08 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strrchr(const char *s, int c)
{
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (*s)
		s++;
	while (*s != (char)c)
		s--;
	return ((char*)s);
}
