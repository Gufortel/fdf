/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnorm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 08:42:35 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/04 05:27:26 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

t_var	*schtypnorm(va_list ap, const char *str, t_var **ptr, int *nbvar)
{
	int		i;
	int		j;
	char	*nb;
	t_var	*p;

	i = 1;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '$')
	{
		p = push_t_var(ptr, arg(*nbvar, ap), NULL);
		p->s = -1;
		return (p);
	}
	nb = (char*)ft_memalloc(i);
	while (++j < i)
		nb[j - 1] = str[j];
	p = push_t_var(ptr, arg(ft_atoi(nb), ap), NULL);
	*nbvar = ft_atoi(nb);
	return (p);
}

void	ft_printfnorm(int *i, int *j, t_var **ptr)
{
	*i = 0;
	*j = 0;
	*ptr = NULL;
	g_nbvar = 0;
	g_exit = 0;
	g_len = 0;
}

int		chroccu(char *str)
{
	int i;

	i = 0;
	while (str[i] != 'a')
		i++;
	return (i);
}

int		printbuffer(t_var *ptr)
{
	char	*buffer;
	t_var	*p;
	int		i;
	int		tmp;

	p = ptr;
	i = 0;
	buffer = ft_memalloc(g_len + 2);
	while (p)
	{
		ft_strcat(buffer + i, p->str);
		i = i + ft_strlen(p->str);
		if (p->s == 42)
		{
			tmp = i - ft_strlen(p->str);
			buffer[chroccu(buffer)] = '\0';
		}
		p = p->next;
	}
	write(1, buffer, g_len);
	ft_strdel(&buffer);
	del_t_var(&ptr);
	g_nbvar = 0;
	return (g_len);
}

void	printfcondition1(int *i, int *j, const char *format, t_var **ptr)
{
	if (format[*j] == '{')
		set_color(format, j, i, ptr);
	elsenorme(format, j, i, ptr);
}
