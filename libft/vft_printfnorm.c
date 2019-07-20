/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vft_printfnorm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 08:42:35 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/31 22:47:02 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		vprintbuffer(t_var *ptr, char **str, int *nbr)
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
	*nbr = *nbr + g_len;
	*str = ft_strcat(*str, buffer);
	del_t_var(&ptr);
	ft_strdel(&buffer);
	g_nbvar = 0;
	return (g_len);
}
