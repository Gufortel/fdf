/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argdate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:09:21 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/18 16:33:28 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	argdate(t_var **lst)
{
	char	*str;
	t_var	*p;

	p = *lst;
	str = ft_itoa((int)p->data);
	p->str = (char*)ft_memalloc(11);
	p->str[0] = str[0];
	p->str[1] = str[1];
	p->str[2] = '/';
	p->str[3] = str[2];
	p->str[4] = str[3];
	p->str[5] = '/';
	p->str[6] = str[4];
	p->str[7] = str[5];
	p->str[8] = str[6];
	p->str[9] = str[7];
}
