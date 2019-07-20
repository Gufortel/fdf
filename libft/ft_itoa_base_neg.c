/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_neg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:31:44 by gufortel          #+#    #+#             */
/*   Updated: 2018/01/20 17:47:09 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa_base_neg(unsigned long long int value, int base)
{
	int							i;
	char						*nbr;
	unsigned long long int		tmp;

	tmp = value;
	i = (value == 0) ? 1 : 0;
	while (tmp)
	{
		tmp = tmp / base;
		i++;
	}
	nbr = (char*)ft_memalloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}
