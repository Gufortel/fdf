/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_wchar_to_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:30:37 by gufortel          #+#    #+#             */
/*   Updated: 2018/01/30 00:07:34 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_len_wchar(wchar_t *wstr)
{
	int i;

	i = 0;
	if (!wstr)
		return (0);
	while (*wstr)
	{
		i = i + ft_val_wchar(*wstr);
		wstr++;
	}
	return (i);
}
