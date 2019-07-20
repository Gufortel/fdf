/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argonorm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:41:32 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/02 16:24:39 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int			argxnorm(t_var **lst, char *tmp)
{
	t_var	*p;
	int		i;

	p = *lst;
	i = 0;
	while (i <= 2)
	{
		if (p->str[i] != ' ')
		{
			tmp[0] = '0';
			tmp[1] = 'x';
			tmp[2] = '\0';
			ft_strcat(tmp, p->str + i);
			ft_strdel(&p->str);
			p->str = tmp;
			if (p->index == 'X')
				ft_strupper(p->str);
			return (1);
		}
		i++;
	}
	return (0);
}

void		contxnorm(char *str, t_var *p, t_var **lst)
{
	if (((str[0] == '0' && p->index != 'p') && p->width != 0) &&
		(p->index != 'p'))
		str[0] = ' ';
	if (str[0] == '0' && p->exact == 0)
		str[0] = '\0';
	if (p->index == 'X' || p->index == 'p' || p->die == 1)
		str = argo_flag(lst, str);
	argo_exac(lst, str);
}
