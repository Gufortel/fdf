/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argbi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:23:24 by gufortel          #+#    #+#             */
/*   Updated: 2018/01/11 21:18:37 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		argbi(t_var **lst)
{
	t_var	*p;
	char	*str;
	int		i;
	int		tmp;

	p = *lst;
	i = -1;
	p->str = ft_itoa_base((int)p->data, 2);
	if (p->width < p->exact)
		str = (char*)ft_memalloc(ft_strlen(p->str) + p->exact);
	else
		str = (char*)ft_memalloc(ft_strlen(p->str) + p->width);
	tmp = p->exact - ft_strlen(p->str);
	while (++i < tmp && p->exact != -1 && tmp >= 0)
		str[i] = '0';
	ft_strcpy(str + i, p->str);
	ft_strdel(&p->str);
	tmp = p->width - ft_strlen(str);
	if ((size_t)p->width > ft_strlen(str))
		ft_memmove(str + (p->width - ft_strlen(str)), str, ft_strlen(str));
	i = -1;
	while (++i < tmp && tmp >= 0)
		str[i] = ' ';
	p->str = ft_strdup(str);
	ft_strdel(&str);
}
