/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:52:27 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/18 16:58:20 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		printlist(t_var *pa)
{
	ft_putstr("die = ");
	ft_putnbr(pa->die);
	ft_putstr("\nzero = ");
	ft_putnbr(pa->zero);
	ft_putstr("\nless = ");
	ft_putnbr(pa->less);
	ft_putstr("\nmore = ");
	ft_putnbr(pa->more);
	ft_putstr("\nspc = ");
	ft_putnbr(pa->spc);
	ft_putstr("\nacco = ");
	ft_putnbr(pa->acco);
	ft_putstr("\nwidth = ");
	ft_putnbr(pa->width);
	ft_putstr("\nexact = ");
	ft_putnbr(pa->exact);
	ft_putstr("\nstool = ");
	ft_putnbr(pa->stool);
	ft_putstr("\nindex = ");
	ft_putchar(pa->index);
	ft_putstr("\n\n");
}

void		printout(t_var *p)
{
	while (p->next)
	{
		if (p->str != NULL)
			ft_putstr(p->str);
		if (p->str == NULL)
			ft_putstr("Q");
		p = p->next;
	}
	if (p->str != NULL)
		ft_putstr(p->str);
	if (p->str == NULL)
		ft_putstr("Q");
}
