/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 02:44:48 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/17 21:29:47 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

t_var			*new_t_var(void *data, char *str)
{
	t_var *p;

	if (!(p = (t_var*)ft_memalloc(sizeof(t_var))))
		exit(42);
	p->s = 1;
	p->die = 0;
	p->zero = 0;
	p->less = 0;
	p->more = 0;
	p->spc = 0;
	p->width = 0;
	p->exact = -1;
	p->stool = 0;
	p->acco = 0;
	p->data = data;
	p->index = '0';
	p->str = str;
	p->next = NULL;
	return (p);
}

t_var			*push_t_var(t_var **begin_list, void *data, char *str)
{
	t_var	*p;

	if (!*begin_list)
	{
		*begin_list = new_t_var(data, str);
		return (*begin_list);
	}
	else
	{
		p = *begin_list;
		while (p->next)
			p = p->next;
		p->next = new_t_var(data, str);
		p = p->next;
	}
	return (p);
}

void			del_t_var_elem(t_var *p)
{
	if (p->str)
		ft_strdel(&p->str);
	if (p)
		free(p);
}

int				del_t_var_elem_exit(t_var *p)
{
	if (p->str)
		ft_strdel(&p->str);
	if (p)
		free(p);
	return (-1);
}

void			del_t_var(t_var **begin_list)
{
	t_var		*p;
	t_var		*tmp;

	if (!*begin_list)
		return ;
	p = *begin_list;
	while (p->next)
	{
		tmp = p->next;
		del_t_var_elem(p);
		p = tmp;
	}
	begin_list = NULL;
	del_t_var_elem(p);
}
