/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 09:37:48 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/02 23:45:16 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		argx(t_var **lst)
{
	t_var	*p;
	int		i;
	char	*tmp;

	p = *lst;
	if (p->index != 'x' && p->index != 'X' && p->index != 'p')
		return ;
	if ((p->die != 1 && (p->index == 'x' || p->index == 'X')) || (p->data == 0
		&& p->index != 'p'))
		return ;
	tmp = (char*)ft_memalloc(ft_strlen(p->str) + 2);
	if (argxnorm(lst, tmp) == 1)
		return ;
	i = 3;
	while (p->str[i])
	{
		if (p->str[i] != ' ' && (p->data != 0 || p->index == 'p'))
		{
			p->str[i - 1] = 'x';
			p->str[i - 2] = '0';
			ft_strdel(&tmp);
			return ;
		}
		i++;
	}
}

void		argo_width(t_var **lst, char c)
{
	t_var	*p;
	int		i;
	int		len;

	p = *lst;
	len = (p->width - 1 == (int)ft_strlen(p->str) && p->index == 'p') ?
	ft_strlen(p->str + 1) : ft_strlen(p->str);
	if ((p->width - 2 >= len && (p->die == 1 || p->index == 'p')) &&
		(p->zero != 0 || p->less == 1))
		p->width -= 2;
	if (p->less == 1)
	{
		i = len;
		while (i < p->width)
			p->str[i++] = ' ';
	}
	else if (len < p->width)
	{
		i = p->width - len;
		ft_memmove(p->str + i, p->str, len);
		i = -1;
		while (i++ < p->width - len - 1)
			p->str[i] = c;
	}
	argx(lst);
}

void		argo_exac(t_var **lst, char *str)
{
	t_var	*p;
	int		i;

	p = *lst;
	i = -1;
	p->str = ((int)ft_strlen(str) < p->exact) ?
		(char*)ft_memalloc(p->exact + p->width + 3) :
		(char*)ft_memalloc(ft_strlen(str) + p->width + 3);
	if (p->exact > (int)ft_strlen(str))
	{
		while (ft_strlen(p->str) < p->exact - ft_strlen(str))
		{
			p->str[++i] = '0';
			p->str[i + 1] = '\0';
		}
	}
	ft_strcat(p->str, str);
	ft_strdel(&str);
	if (p->zero == 1 && p->exact == -1)
		argo_width(lst, '0');
	else
		argo_width(lst, ' ');
}

char		*argo_flag(t_var **lst, char *str)
{
	char	*tmp;
	t_var	*p;
	int		i;

	i = 0;
	p = *lst;
	tmp = (char*)ft_memalloc(ft_strlen(str) + 4);
	if ((p->index == 'o' || p->index == 'O') && ((p->data != 0 ||
		(p->die == 1 && p->exact != -1))))
	{
		tmp[i] = '0';
		tmp[i + 1] = '\0';
	}
	ft_strcat(tmp, str);
	ft_strdel(&str);
	if (p->index == 'X')
		ft_strupper(tmp);
	return (tmp);
}

void		argo(t_var **lst, int base)
{
	char		*str;
	t_var		*p;

	p = *lst;
	if (p->stool == 1 && p->index != 'U')
		str = ft_itoa_base((unsigned short int)p->data, base);
	else if (p->stool == 2)
		str = ft_itoa_base((unsigned char)p->data, base);
	else if (p->stool == 3 || (p->index == 'U') || p->index == 'p')
		str = ft_itoa_base_neg((unsigned long int)p->data, base);
	else if (p->stool == 4)
		str = ft_itoa_base_neg((unsigned long long int)p->data, base);
	else if (p->stool == 7)
		str = ft_itoa_base_neg((uintmax_t)p->data, base);
	else if (p->stool == 8)
		str = ft_itoa_base_neg((ssize_t)p->data, base);
	else if (p->stool == 9)
		str = ft_itoa_base((unsigned char)p->data, base);
	else
		str = ft_itoa_base((unsigned int)p->data, base);
	contxnorm(str, p, lst);
}
