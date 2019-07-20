/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 06:15:22 by gufortel          #+#    #+#             */
/*   Updated: 2018/07/14 06:20:03 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_strstri(char *str, char *to_find, int i)
{
	int		j;
	int		adr;

	adr = 0;
	while (str[i])
	{
		j = i;
		adr = 0;
		while (str[j] == to_find[adr])
		{
			j++;
			adr++;
			if (!(to_find[adr]))
				return (i);
		}
		i++;
	}
	return (0);
}
