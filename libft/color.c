/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:21:14 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/17 20:44:31 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int			chkcolor3(char *str, t_var **ptr)
{
	if (ft_strcmp(str, "LIGHT") == 0)
		push_t_var(ptr, NULL, ft_strdup(LIGHT));
	else if (ft_strcmp(str, "DARK") == 0)
		push_t_var(ptr, NULL, ft_strdup(DARK));
	else if (ft_strcmp(str, "ITALIC") == 0)
		push_t_var(ptr, NULL, ft_strdup(ITALIC));
	else if (ft_strcmp(str, "UNDERLINE") == 0)
		push_t_var(ptr, NULL, ft_strdup(UNDERLINE));
	else if (ft_strcmp(str, "CLEAR") == 0)
		push_t_var(ptr, NULL, ft_strdup(CLEAR));
	else
		return (-1);
	return (0);
}

int			chkcolor2(char *str, t_var **ptr)
{
	if (ft_strcmp(str, "B_RED") == 0)
		push_t_var(ptr, NULL, ft_strdup(B_RED));
	else if (ft_strcmp(str, "B_BLACK") == 0)
		push_t_var(ptr, NULL, ft_strdup(B_BLACK));
	else if (ft_strcmp(str, "B_GREEN") == 0)
		push_t_var(ptr, NULL, ft_strdup(B_GREEN));
	else if (ft_strcmp(str, "B_YELLOW") == 0)
		push_t_var(ptr, NULL, ft_strdup(B_YELLOW));
	else if (ft_strcmp(str, "B_BLUE") == 0)
		push_t_var(ptr, NULL, ft_strdup(B_BLUE));
	else if (ft_strcmp(str, "B_PURPLE") == 0)
		push_t_var(ptr, NULL, ft_strdup(B_PURPLE));
	else if (ft_strcmp(str, "B_CYAN") == 0)
		push_t_var(ptr, NULL, ft_strdup(B_CYAN));
	else if (ft_strcmp(str, "B_GREY") == 0)
		push_t_var(ptr, NULL, ft_strdup(B_GREY));
	else
		return (chkcolor3(str, ptr));
	return (0);
}

int			chkcolor(char *str, t_var **ptr)
{
	if (ft_strcmp(str, "RED") == 0)
		push_t_var(ptr, NULL, ft_strdup(RED));
	else if (ft_strcmp(str, "BLACK") == 0)
		push_t_var(ptr, NULL, ft_strdup(BLACK));
	else if (ft_strcmp(str, "GREEN") == 0)
		push_t_var(ptr, NULL, ft_strdup(GREEN));
	else if (ft_strcmp(str, "YELLOW") == 0)
		push_t_var(ptr, NULL, ft_strdup(YELLOW));
	else if (ft_strcmp(str, "BLUE") == 0)
		push_t_var(ptr, NULL, ft_strdup(BLUE));
	else if (ft_strcmp(str, "PURPLE") == 0)
		push_t_var(ptr, NULL, ft_strdup(PURPLE));
	else if (ft_strcmp(str, "CYAN") == 0)
		push_t_var(ptr, NULL, ft_strdup(CYAN));
	else if (ft_strcmp(str, "GREY") == 0)
		push_t_var(ptr, NULL, ft_strdup(GREY));
	else if (ft_strcmp(str, "EOC") == 0)
		push_t_var(ptr, NULL, ft_strdup(DEFAULT));
	else
		return (chkcolor2(str, ptr));
	return (0);
}

void		lenlen(t_var **ptr)
{
	t_var	*p;
	int		i;

	p = *ptr;
	i = 0;
	while (p->next)
		p = p->next;
	while (p->str[i] != 'm' && p->str[i] != 'J')
		i++;
	g_len = g_len + i + 1;
}

void		set_color(const char *str, int *j, int *i, t_var **ptr)
{
	char	*tmp;

	while (str[*j] != '}')
		*j = *j + 1;
	tmp = ft_strsub(str, *i + 1, *j - *i - 1);
	if (chkcolor(tmp, ptr) == 0)
	{
		*i = *j + 1;
		lenlen(ptr);
	}
	else
		*j = *i + 1;
	ft_strdel(&tmp);
}
