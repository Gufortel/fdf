/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 07:39:41 by gufortel          #+#    #+#             */
/*   Updated: 2018/02/25 02:37:40 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		parseatrib(char *str, t_var **lst)
{
	t_var		*p;

	p = *lst;
	if (ft_strstr(str, "#"))
		p->die = 1;
	if (ft_strstr(str, "0"))
		p->zero = 1;
	if (ft_strstr(str, "-"))
		p->less = 1;
	if (ft_strstr(str, "+"))
		p->more = 1;
	if (ft_strstr(str, " "))
		p->spc = 1;
	if (ft_strstr(str, "'"))
		p->acco = 1;
	if (p->less == 1 && p->zero == 1)
		p->zero = 0;
	if (p->more == 1 && p->spc == 1)
		p->spc = 0;
}

void		parseflag(char *str, t_var **lst)
{
	t_var		*p;

	p = *lst;
	if (ft_strstr(str, "h"))
		p->stool = 1;
	if (ft_strstr(str, "hh"))
		p->stool = 2;
	if (ft_strstr(str, "l"))
		p->stool = 3;
	if (ft_strstr(str, "ll") || ft_strstr(str, "q"))
		p->stool = 4;
	if (ft_strstr(str, "L"))
		p->stool = 5;
	if (ft_strstr(str, "H"))
		p->stool = 6;
	if (ft_strstr(str, "j"))
		p->stool = 7;
	if (ft_strstr(str, "z"))
		p->stool = 8;
	if (ft_strstr(str, "D"))
		p->stool = 9;
	if (ft_strstr(str, "DD"))
		p->stool = 10;
}

void		parse1(t_var **lst, char *str, int *j, int *i)
{
	t_var	*ptr;

	ptr = *lst;
	*i = *j;
	while (str[*j] != 'd' && str[*j] != 'i' && str[*j] != 'o' && str[*j] != 'u'
		&& str[*j] != 'x' && str[*j] != 'X' && str[*j] != 'c' && str[*j] != 's'
		&& str[*j] != 'p' && str[*j] != 'n' && str[*j] != 'm' && str[*j] != '%'
		&& str[*j] != 'C' && str[*j] != 'S' && str[*j] != 'O' && str[*j] != 'U'
		&& str[*j] != 'D' && str[*j] != 'b' && str[*j] != 'r' && str[*j] != 'k'
		&& str[*j] != 'K' && str[*j] != '\0')
		*j = *j + 1;
	ptr->str = ft_strsub(str, *i, *j - *i);
	parseflag(ptr->str, lst);
	ft_strdel(&ptr->str);
	ptr->index = str[*j];
	if (ptr->index == '\0')
		ptr->index = '\0';
}

/*
** la fonction parse2 gere la precision et une fois
** tout les parametres rentre dans le maillon on
** appelle la fonction treatarg() pour traiter les
** argument celon les parametres.
*/

void		parse2(t_var **lst, char *str, va_list ap)
{
	int		i;
	int		j;
	t_var	*ptr;

	i = 0;
	j = 0;
	ptr = *lst;
	if (str[i] == '.')
		i++;
	if (str[i] == '*' && str[i - 1] == '.')
	{
		i++;
		j = i;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		ptr->str = ft_strsub(str, j, i - j);
		parsenorm3(lst, ap);
		ft_strdel(&ptr->str);
	}
	else if (str[i - 1] == '.')
		parse2norme(ptr, str, &i, &j);
	parse1(lst, str, &i, &j);
	ft_strdel(&str);
	ptr->exact = (ptr->exact < 0) ? -1 : ptr->exact;
	treatarg(lst);
}

int			parse(t_var **lst, char *str, va_list ap)
{
	t_var	*ptr;
	int		i;
	int		j;

	ptr = *lst;
	i = 1;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '$')
		i++;
	else
		i = 1;
	j = i;
	while (str[i] == '#' || str[i] == '0' || str[i] == '+'
			|| str[i] == '-' || str[i] == ' ')
		i++;
	ptr->str = ft_strsub(str, j, i - j);
	parseatrib(ptr->str, lst);
	ft_strdel(&ptr->str);
	parsenorm(lst, str, ap, &i);
	ft_strdel(&str);
	return (i);
}
