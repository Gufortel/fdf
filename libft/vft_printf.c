/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 00:33:36 by lmoreaux          #+#    #+#             */
/*   Updated: 2018/03/17 05:53:31 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "./includes/ft_printf.h"
#include <locale.h>

int		vft_printf(char **str, int *nbr, const char *format, ...)
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
	return (vprintbuffer(ptr, str, nbr));
}
