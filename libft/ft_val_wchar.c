/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:30:38 by gufortel          #+#    #+#             */
/*   Updated: 2018/01/29 23:58:47 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_val_wchar(wchar_t letter)
{
	int		size;

	size = 0;
	if (letter <= 0x7F)
		size = 1;
	else if (letter <= 0x7FF)
		size = 2;
	else if (letter <= 0xFFFF)
		size = 3;
	else if (letter <= 0x10FFFF)
		size = 4;
	return (size);
}
