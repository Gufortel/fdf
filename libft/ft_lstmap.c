/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 09:35:51 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/11 11:18:22 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*p;
	t_list		*ptr;

	if (!lst || !f)
		return (NULL);
	p = f(lst);
	if (!(list = ft_lstnew(p->content, p->content_size)))
		return (NULL);
	lst = lst->next;
	ptr = list;
	while (lst)
	{
		p = f(lst);
		if (!(ptr->next = ft_lstnew(p->content, p->content_size)))
			return (NULL);
		lst = lst->next;
		ptr = ptr->next;
	}
	ptr->next = NULL;
	return (list);
}
