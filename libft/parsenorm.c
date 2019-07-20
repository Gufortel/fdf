/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsenorm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 07:43:09 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/04 01:00:22 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		parsenorm3(t_var **lst, va_list ap)
{
	t_var *ptr;

	ptr = *lst;
	if (ft_atoi(ptr->str) == 0)
	{
		ptr->exact = (int)arg(g_nbvar, ap);
		ptr->data = arg(1, ap);
		g_nbvar += 1;
	}
	else
		ptr->exact = (int)arg(ft_atoi(ptr->str), ap);
}

void		parsenorm2(t_var **lst, char *str, va_list ap, int *i)
{
	int		j;
	t_var	*ptr;

	ptr = *lst;
	*i = *i + 1;
	j = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
		*i = *i + 1;
	ptr->str = ft_strsub(str, j, *i - j);
	if (ft_atoi(ptr->str) == 0)
	{
		ptr->width = (int)arg(g_nbvar, ap);
		ptr->data = arg(1, ap);
		g_nbvar += 1;
	}
	else
		ptr->width = (int)arg(ft_atoi(ptr->str), ap);
	ft_strdel(&ptr->str);
}

void		parsenorm(t_var **lst, char *str, va_list ap, int *i)
{
	int		j;
	t_var	*ptr;

	ptr = *lst;
	if (str[*i] == '*')
		parsenorm2(lst, str, ap, i);
	else
	{
		j = *i;
		while (str[*i] >= '0' && str[*i] <= '9')
			*i = *i + 1;
		ptr->str = ft_strsub(str, j, *i - j);
		ptr->width = ft_atoi(ptr->str);
		ft_strdel(&ptr->str);
	}
	if (ptr->width < 0)
	{
		ptr->width = -ptr->width;
		ptr->less = 1;
	}
}

void		parse2norme(t_var *ptr, char *str, int *i, int *j)
{
	*j = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
		*i = *i + 1;
	ptr->str = ft_strsub(str, *j, *i - *j);
	ptr->exact = ft_atoi(ptr->str);
	ft_strdel(&ptr->str);
}
