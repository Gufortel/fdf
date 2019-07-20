/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:51:53 by gufortel          #+#    #+#             */
/*   Updated: 2019/02/13 18:13:16 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		arg2(t_var **lst)
{
	t_var	*p;

	p = *lst;
	if (p->index == 'o' || p->index == 'O')
		argo(lst, 8);
	else if (p->index == 'u' || p->index == 'U' || p->index == 'D')
		argo(lst, 10);
	else if (p->index == 'x' || p->index == 'X' || p->index == 'p')
		argo(lst, 16);
}

void		arg3(t_var **lst)
{
	t_var	*p;

	p = *lst;
	if (p->index == 'C' || (p->index == 'c' && p->stool == 3))
		argcc(lst);
	else if (p->index == 'c')
		argc(lst);
	else if (p->index == 'S' || (p->index == 's' && p->stool == 3))
		argss(lst);
	else if (p->index == 's')
		args(lst);
}
