/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 09:03:52 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/11 10:20:09 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;
	t_list		*p;

	if (!alst)
		return ;
	list = *alst;
	while (list->next)
	{
		p = list->next;
		ft_lstdelone(&list, del);
		list = p;
	}
	*alst = NULL;
	ft_lstdelone(&list, del);
}
