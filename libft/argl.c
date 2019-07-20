/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:31:56 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/18 16:34:15 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	arglst(t_var **lst)
{
	t_var	*p;
	char	*str;
	int		i;

	p = *lst;
	i = 0;
	str = (char*)p->data;
	p->str = (char*)ft_memalloc(ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] == ' ')
			p->str[i] = '\n';
		else
			p->str[i] = str[i];
		i++;
	}
}
