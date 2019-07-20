/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 02:11:34 by lmoreaux          #+#    #+#             */
/*   Updated: 2018/02/24 04:16:20 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	space(t_var **lst, char *data)
{
	t_var	*ptr;
	int		i;
	char	*c;
	int		o;
	int		d;

	ptr = *lst;
	d = ft_strlen(data);
	o = -1;
	i = (d < ptr->exact && ptr->width > ptr->exact) ?
		ptr->width - ptr->exact + 1 : ptr->width -
		ft_strlen(data + 1);
	if (ptr->width > ptr->exact && ptr->more == 0 && ptr->spc == 0)
		i++;
	if (!(c = (char *)ft_memalloc((sizeof(char) * i) + 1)))
		return ;
	while (--i > 0)
		c[++o] = (ptr->zero == 1 && ptr->less == 0
				&& ptr->exact < 0) ? '0' : ' ';
	c[o] = '\0';
	ft_strcat(ptr->str, c);
	free(c);
}

void	rempli(long long int c, int i, t_var **lst, char *data)
{
	t_var	*ptr;
	int		o;
	int		a;
	int		b;

	ptr = *lst;
	b = (c >= 0) ? c : c * -1;
	if (ptr->spc == 1 && c >= 0)
		a = 1;
	else
		a = 0;
	o = ptr->exact - i + 1;
	if (c < 0)
		o++;
	if (c < 0)
		ptr->str[a++] = '-';
	if (c >= 0 && ptr->more == 1)
		ptr->str[a++] = '+';
	while (--o > 0)
	{
		ptr->str[a] = '0';
		a++;
	}
	ptr->str[a] = '\0';
	ft_strcat(ptr->str, data);
}

void	widthdless2(long long int b, int i, t_var **lst, char *data)
{
	t_var	*ptr;

	ptr = *lst;
	if (ptr->less == 1 && i <= ptr->exact && ptr->width <= ptr->exact)
		rempli(b, i, lst, data);
	else if (i >= ptr->exact && i >= ptr->width)
	{
		if (ptr->more == 1 && b >= 0)
			ptr->str[0] = '+';
		ft_strcat(ptr->str, data);
		if (b == 0 && ptr->stool == 0 && ptr->more == 0 && (ptr->width !=
					0 || ptr->exact != -1))
			ptr->str[ft_strlen(ptr->str) - i] = '\0';
	}
	else if (ptr->less == 1 && i < ptr->width && i >= ptr->exact)
	{
		ft_strcat(ptr->str, data);
		space(lst, data);
	}
	else if (ptr->less == 0)
		widthdmore(b, i, lst, data);
}

void	widthdless(long long int b, t_var **lst, char *data)
{
	t_var	*ptr;
	int		i;
	char	*spc;

	ptr = *lst;
	if (!(spc = (char *)ft_memalloc(sizeof(char) * 2)))
		return ;
	spc[0] = ' ';
	spc[1] = '\0';
	i = ft_strlen(data);
	if (!(ptr->str = (char *)ft_memalloc((sizeof(char) *
		(ptr->width + ptr->exact + i)) + 2)))
		return ;
	if (b >= 0 && ptr->spc == 1)
		ft_strcat(ptr->str, spc);
	free(spc);
	if (ptr->less == 1 && i < ptr->exact && ptr->width > ptr->exact)
	{
		rempli(b, i, lst, data);
		space(lst, data);
	}
	else
		(widthdless2(b, i, lst, data));
}

void	convd(t_var **lst)
{
	t_var			*ptr;
	long long int	b;
	char			*data;

	ptr = *lst;
	if (ptr->stool == 0)
		b = (int)ptr->data;
	if (ptr->stool == 1)
		b = (short int)ptr->data;
	if (ptr->stool == 2)
		b = (signed char)ptr->data;
	if (ptr->stool == 3)
		b = (long int)ptr->data;
	if (ptr->stool == 4)
		b = (long long int)ptr->data;
	if (ptr->stool == 7)
		b = (unsigned long long int)ptr->data;
	if (ptr->stool == 8)
		b = (size_t)ptr->data;
	data = ft_itoa(b);
	widthdless(b, lst, data);
	free(data);
}
