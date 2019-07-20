/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:40:39 by gufortel          #+#    #+#             */
/*   Updated: 2018/07/10 01:13:01 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	while (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n')
		j--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		j--;
	if (j <= 0)
		j = 0;
	str = (char*)ft_memalloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < j)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
