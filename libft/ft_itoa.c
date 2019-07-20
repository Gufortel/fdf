/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:01:30 by gufortel          #+#    #+#             */
/*   Updated: 2018/07/10 01:09:11 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		ft_rev(char *str, int i, int j, unsigned int nb)
{
	char	tmp;

	str[i] = nb + '0';
	str[i + 1] = '\0';
	while (j < i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j++;
		i--;
	}
}

static int		ft_cp(int n)
{
	int				tmp;
	unsigned int	nb;

	tmp = 0;
	if (n < 0)
	{
		nb = -n;
		tmp++;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		tmp++;
	}
	return (tmp + 1);
}

char			*ft_itoa(long long int n)
{
	int				i;
	int				j;
	char			*str;
	unsigned int	nb;

	if (!(str = ft_memalloc(ft_cp(n) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		j++;
		nb = -n;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		str[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	ft_rev(str, i, j, nb);
	return (str);
}
