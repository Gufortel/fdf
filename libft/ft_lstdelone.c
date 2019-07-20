/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 08:38:01 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/11 10:18:29 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*p;

	p = *alst;
	del(p->content, (p->content_size));
	ft_memdel((void**)alst);
}
