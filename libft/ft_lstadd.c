/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 09:24:12 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/11 10:42:12 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	t_list		*list;
	t_list		*p;

	if (!*alst)
	{
		*alst = new;
		new->next = NULL;
		return ;
	}
	list = *alst;
	p = list->next;
	*alst = new;
	new->next = p;
}
