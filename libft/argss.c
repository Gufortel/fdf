/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 00:43:56 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/05 10:53:53 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		count_argss(wchar_t *str, t_var **lst)
{
	int		len;
	int		add;
	t_var	*p;

	len = 0;
	add = 0;
	p = *lst;
	while (*str && (len <= p->exact || p->exact == -1))
	{
		if (ft_val_wchar(*str) > MB_CUR_MAX)
		{
			g_exit = -1;
			return (-1);
		}
		add = ft_val_wchar(*str);
		len = len + add;
		str++;
	}
	if (len > p->exact && p->exact != -1)
		len = len - add;
	return (len);
}

void	argss(t_var **lst)
{
	int		len;
	int		i;
	wchar_t	*tmp;
	t_var	*p;

	p = *lst;
	i = 0;
	tmp = (p->data != NULL) ? (wchar_t*)p->data : (wchar_t)0;
	len = (tmp != (wchar_t)0) ? count_argss(tmp, lst) : 6;
	p->str = (char*)ft_memalloc(len + p->width + 2);
	while (i < (p->width - len))
		p->str[i++] = ' ';
	if (p->width > len)
		len = len + (p->width - len);
	while (i < len)
	{
		if (tmp != (wchar_t)0)
			i = wstring(*tmp, p->str, i, 0);
		else
		{
			ft_strcpy(p->str + i, "(null)");
			return ;
		}
		tmp++;
	}
}
