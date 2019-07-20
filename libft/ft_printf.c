/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 00:33:36 by lmoreaux          #+#    #+#             */
/*   Updated: 2018/02/25 04:30:40 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "./includes/ft_printf.h"
#include <locale.h>

void	*arg(int nb, va_list ap)
{
	int		i;
	void	*vid;

	i = 1;
	while (i < nb)
	{
		va_arg(ap, void*);
		i++;
	}
	vid = va_arg(ap, void*);
	va_end(ap);
	return (vid);
}

t_var	*schtyp(va_list ap, const char *str, t_var **ptr, int *nbvar)
{
	int		i;
	t_var	*p;

	i = 1;
	if (str[i] > '0' && str[i] <= '9')
		p = schtypnorm(ap, str, ptr, nbvar);
	else
		p = push_t_var(ptr, arg(*nbvar, ap), NULL);
	p->s = -1;
	return (p);
}

t_var	*elem(const char *str, int *j, t_var **ptr, va_list ap)
{
	t_var	*tmp;
	int		nb;

	g_nbvar++;
	nb = 0;
	tmp = schtyp(ap, str + *j, ptr, &g_nbvar);
	*j = *j + 1;
	while (str[*j] != 'd' && str[*j] != 'i' && str[*j] != 'o' && str[*j] != 'u'
		&& str[*j] != 'x' && str[*j] != 'X' && str[*j] != 'c' && str[*j] != 's'
		&& str[*j] != 'p' && str[*j] != 'n' && str[*j] != 'm' && str[*j] != '%'
		&& str[*j] != 'C' && str[*j] != 'S' && str[*j] != 'O' && str[*j] != 'U'
		&& str[*j] != 'D' && str[*j] != 'b' && str[*j] != 'r' && str[*j] != 'k'
		&& str[*j] != 'K' && str[*j] != '\0')
	{
		*j = *j + 1;
		nb++;
	}
	if (str[*j] == 'm' || str[*j] == 'n' || str[*j] == '%' || str[*j] == '%')
		g_nbvar--;
	if (str[*j] == '\0')
		return (tmp);
	*j = *j + 1;
	return (tmp);
}

void	elsenorme(const char *format, int *j, int *i, t_var **ptr)
{
	t_var	*tmp;

	while (format[*j] != '%' && format[*j] != '\0' && format[*j] != '{')
		*j = *j + 1;
	tmp = push_t_var(ptr, NULL, ft_strsub(format, *i, *j - *i));
	tmp->s = 1;
	g_len = g_len + ft_strlen(tmp->str);
	*i = *j;
}

int		ft_printf(const char *format, ...)
{
	int			i;
	int			j;
	t_var		*pa;
	t_var		*ptr;
	va_list		ap;

	ft_printfnorm(&i, &j, &ptr);
	while (format[j])
	{
		if (format[j] == '%')
		{
			i = j;
			va_start(ap, format);
			pa = elem(format, &j, &ptr, ap);
			va_start(ap, format);
			i = i + parse(&pa, ft_strsub(format, i, j - i), ap);
			va_start(ap, format);
			parse2(&pa, ft_strsub(format, i, j - i), ap);
			if (g_exit == -1)
				return (del_t_var_elem_exit(ptr));
			i = j;
		}
		printfcondition1(&i, &j, format, &ptr);
	}
	return (printbuffer(ptr));
}
