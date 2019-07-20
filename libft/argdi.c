/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argdi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:48:48 by gufortel          #+#    #+#             */
/*   Updated: 2018/01/12 01:02:17 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	argdi(t_var **lst)
{
	t_var	*p;
	int		i;
	char	c;

	p = *lst;
	i = -1;
	c = (p->zero == 1) ? '0' : ' ';
	if (p->width == 0)
		p->width = 1;
	p->str = (char*)ft_memalloc(p->width + 1);
	if (p->less == 1)
		p->str[++i] = '%';
	while (++i < p->width - (1 - p->less))
		p->str[i] = c;
	if (p->less == 0)
		p->str[i] = '%';
}
