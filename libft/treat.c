/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 09:18:51 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/18 16:37:47 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	treatarg2(t_var **lst)
{
	t_var *p;

	p = *lst;
	if (p->index == 'r')
		unprint(lst);
	if (p->index == 'm')
		argerrno(lst);
	if (p->index == 'b')
		argbi(lst);
	if (p->index == '%')
		argdi(lst);
	if (p->index == 'n')
		argnb(lst);
	if (p->index == 'k')
		arglst(lst);
	if (p->index == 'K')
		argdate(lst);
	if (p->index == '\0')
		p->str = ft_strdup("\0");
	g_len = g_len + ft_strlen(p->str);
}

void	treatarg(t_var **lst)
{
	t_var	*p;

	p = *lst;
	if ((p->stool == 1 || p->stool == 2) && (p->index == 'D'
	|| p->index == 'O' || p->index == 'U'))
		p->stool = 0;
	if (p->stool == 0 && (p->index == 'D' || p->index == 'O'
	|| p->index == 'U'))
		p->stool = 3;
	if (p->index == 'o' || p->index == 'u' || p->index == 'x' || p->index == 'X'
	|| p->index == 'O' || p->index == 'U' || p->index == 'p' || p->index == 'D'
	|| (p->index == 'D' && p->stool == 1) || (p->index == 'D' && p->stool == 2))
		arg2(lst);
	if (p->index == 'd' || p->index == 'i' || (p->index == 'D' &&
	p->stool == 3) || (p->index == 'D' && p->stool == 4) || (p->index == 'D'
	&& p->stool == 7) || (p->index == 'D' && p->stool == 8))
		convd(lst);
	if (p->index == 'c' || p->index == 'C' || p->index == 's'
		|| p->index == 'S')
		arg3(lst);
	treatarg2(lst);
}
