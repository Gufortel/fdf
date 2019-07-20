/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:40:22 by lmoreaux          #+#    #+#             */
/*   Updated: 2018/01/11 19:27:09 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	table(char *str, int j)
{
	int		a;
	char	*src;

	a = str[j];
	if (a >= 10)
	{
		ft_memmove(str + j + 3, str + j + 1, ft_strlen(str + j + 1));
		str[j] = '\\';
		src = ft_itoa(a);
		ft_memcpy(str + j + 1, src, 2);
	}
	if (a < 10)
	{
		ft_memmove(str + j + 2, str + j + 1, ft_strlen(str + j + 1));
		str[j] = '\\';
		src = ft_itoa(a);
		ft_memcpy(str + j + 1, src, 1);
	}
	ft_strdel(&src);
}

void	unprint(t_var **lst)
{
	t_var	*ptr;
	char	*str;
	int		i;
	int		j;

	ptr = *lst;
	j = 0;
	i = ft_strlen((char*)ptr->data);
	if (!(str = (char *)ft_memalloc((sizeof(char) * i) * 3 + 1)))
		return ;
	str = ft_strcat(str, (char*)ptr->data);
	str[i + 1] = '\0';
	while (str[j] != '\0')
	{
		if (str[j] >= 0 && str[j] <= 31)
			table(str, j);
		j++;
	}
	ptr->str = ft_strdup(str);
	ft_strdel(&str);
}
