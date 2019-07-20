/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convnorme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:22:42 by lmoreaux          #+#    #+#             */
/*   Updated: 2018/02/24 04:02:34 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	spaceb(int o, long long int b, int d, t_var **lst)
{
	t_var	*ptr;
	int		i;
	char	*c;

	ptr = *lst;
	i = (d < ptr->exact && ptr->width >= ptr->exact) ?
		ptr->width - ptr->exact : 0;
	if (i == 0 && d == ptr->exact)
		i = ptr->width - ptr->exact;
	if (i == 0)
		i = (d > ptr->exact && ptr->width > d) ? ptr->width - d : 0;
	c = (char *)ft_memalloc((sizeof(char) * i) + 1);
	if ((ptr->more == 1 && b > 0) || (ptr->spc == 1) ||
			((int)ptr->data < 0 && ptr->width > 10 && ptr->exact >= d))
		i--;
	if (ptr->zero == 1 && (ptr->more == 1 || b < 0) &&
			(ptr->str[1] != '+' && ptr->str[1] != '-'))
		ptr->str[0] = (b >= 0) ? '+' : '-';
	if (b < 0)
		d += 1;
	while (i-- > 0)
		c[o++] = ptr->zero == 1 && ptr->less == 0 && ptr->exact < d
		? '0' : ' ';
	ft_strcat(ptr->str, c);
	free(c);
}

void	remplimore(long long int c, int i, t_var **lst, char *data)
{
	t_var	*ptr;
	int		o;
	int		a;
	int		b;

	ptr = *lst;
	b = c * -1;
	if (i == 1 && data[0] == '0' && ptr->exact == -1 && ptr->spc == 0)
		return ;
	a = (ptr->width == ptr->exact) ? 0 : ft_strlen(ptr->str);
	o = ptr->exact - i + 1;
	if (ptr->str[0] != '-' && ptr->str[0] != '+' &&
			(ft_atoi(data) > 0 || ptr->zero == 0))
	{
		if (((((ptr->more == 1 || c < 0) && (ptr->zero == 0 ||
		(ptr->zero == 1 && ptr->exact > i))) ||
		(ptr->more == 1 && ptr->zero == 1)) && ptr->str[a - 1] != '-'))
			ptr->str[a++] = (c >= 0) ? '+' : '-';
	}
	if (ptr->str[a - 1] == '-')
		o++;
	while (--o > 0)
		ptr->str[a++] = '0';
	ptr->str[a] = '\0';
	ft_strcat(ptr->str, data);
}

void	widthdmore(long long int b, int i, t_var **lst, char *data)
{
	t_var	*ptr;
	int		o;

	o = 0;
	ptr = *lst;
	if (data[0] == '-')
	{
		ft_bzero(data, i);
		data = ft_itoa((int)ptr->data * -1);
	}
	if (i < ptr->exact && ptr->width == 0)
		remplimore(b, i, lst, data);
	else if ((i <= ptr->exact && ptr->width > ptr->exact) ||
			(i < ptr->width || i < ptr->exact))
	{
		spaceb(o, b, i, lst);
		remplimore(b, i, lst, data);
		if (b == 0 && ptr->zero == 0)
			ptr->str[ft_strlen(ptr->str) - i] = ' ';
	}
	else if (i < ptr->width && i >= ptr->exact)
	{
		spaceb(o, b, i, lst);
		ft_strcat(ptr->str, data);
	}
}
