/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:15:16 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/04 13:21:56 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	argc(t_var **lst)
{
	t_var	*p;
	int		i;

	p = *lst;
	i = 0;
	p->str = (char*)ft_memalloc(p->width + 2);
	if (p->data == NULL)
	{
		p->data = (void*)'a';
		p->s = 42;
	}
	p->str[i] = (p->less == 0) ? '\0' : (char)p->data;
	if (p->less == 1)
		i++;
	while (i < p->width)
	{
		p->str[i] = (p->zero == 0) ? ' ' : '0';
		i++;
	}
	if (p->width == 0)
		p->width = 1;
	p->str[p->width - 1] = (p->less == 1) ? ' ' : (char)p->data;
}

int		wstring(wchar_t wstr, char *str, int i, int size)
{
	size = ft_val_wchar(wstr);
	if (wstr <= 255 && MB_CUR_MAX == 1)
		str[i++] = (char)wstr;
	else if (size == 1)
		str[i++] = (char)wstr;
	else if (size == 2)
	{
		str[i++] = (wstr >> 6) + 0xc0;
		str[i++] = (wstr & 0x3f) + 0x80;
	}
	else if (size == 3)
	{
		str[i++] = (wstr >> 12) + 0xe0;
		str[i++] = ((wstr >> 6) & 0x3f) + 0x80;
		str[i++] = (wstr & 0x3f) + 0x80;
	}
	else
	{
		str[i++] = (wstr >> 18) + 0xf0;
		str[i++] = ((wstr >> 12) & 0x0f) + 0x80;
		str[i++] = ((wstr >> 6) & 0x0f) + 0x80;
		str[i++] = (wstr & 0x3f) + 0x80;
	}
	return (i);
}

void	argcc(t_var **lst)
{
	t_var	*p;
	int		i;
	wchar_t	letter[2];

	p = *lst;
	i = 0;
	if (p->data == 0)
	{
		argc(lst);
		return ;
	}
	letter[0] = (wchar_t)p->data;
	letter[1] = '\0';
	p->str = (char*)ft_memalloc(p->width + ft_len_wchar(letter) + 2);
	while (i < p->width - 1)
	{
		p->str[i] = ' ';
		i++;
	}
	if (ft_val_wchar((wchar_t)p->data) > MB_CUR_MAX)
	{
		g_exit = -1;
		return ;
	}
	i = wstring((wchar_t)p->data, p->str, i, 0);
}

void	argsnorm(t_var *p, int *spc, int *i)
{
	if (p->exact != -1 && p->less == 0)
		ft_strlcat(p->str, (char*)p->data, p->exact + *spc + 1);
	else if (p->exact != -1 && p->less == 1)
		ft_strlcat(p->str, (char*)p->data, p->exact + 1);
	else
		ft_strcat(p->str, (char*)p->data);
	*i = ft_strlen((char*)p->str) - 1;
	*spc = *spc + ft_strlen((char*)p->str);
}

void	args(t_var **lst)
{
	t_var	*p;
	int		i;
	int		spc;

	p = *lst;
	i = -1;
	spc = 0;
	p->data = (p->data == NULL) ? "(null)" : p->data;
	p->exact = ((size_t)p->exact > ft_strlen((char*)p->data))
	? ft_strlen((char*)p->data) : p->exact;
	if (p->width > p->exact)
	{
		if (p->exact != -1)
			spc = p->width - ((ft_strlen((char*)p->data) + p->exact)
			- ft_strlen((char*)p->data));
		else
			spc = p->width - ft_strlen((char*)p->data);
	}
	p->str = (char*)ft_memalloc(ft_strlen((char*)p->data) + p->width + 1);
	if (p->less == 1)
		argsnorm(p, &spc, &i);
	while (++i < spc)
		p->str[i] = (p->zero == 0) ? ' ' : '0';
	if (p->less == 0)
		argsnorm(p, &spc, &i);
}
