/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 05:00:00 by gufortel          #+#    #+#             */
/*   Updated: 2018/03/15 06:40:41 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int						neg;
	unsigned long long		nb;
	int						i;

	neg = 1;
	nb = 0;
	i = 0;
	while (*str == '\v' || *str == '\f' || *str == '\n'
			|| *str == '\t' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = 10 * nb + *str - '0';
		str++;
		i++;
	}
	if (i > 19 || nb >= 9223372036854775807uLL)
		return (neg == 1 ? -1 : 0);
	return (nb * neg);
}
