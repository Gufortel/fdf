/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 03:30:50 by gufortel          #+#    #+#             */
/*   Updated: 2018/01/08 17:29:17 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int			index2(char c)
{
	if (c == 'a')
		return (12);
	if (c == 'A')
		return (13);
	if (c == 'c')
		return (14);
	if (c == 's')
		return (15);
	if (c == 'C')
		return (16);
	if (c == 'S')
		return (17);
	if (c == 'p')
		return (18);
	if (c == 'n')
		return (19);
	if (c == 'm')
		return (20);
	if (c == '%')
		return (21);
	if (c == 'G')
		return (11);
	return (-1);
}

int			index1(char c)
{
	if (c == 'd')
		return (0);
	if (c == 'i')
		return (1);
	if (c == 'o')
		return (2);
	if (c == 'u')
		return (3);
	if (c == 'x')
		return (4);
	if (c == 'X')
		return (5);
	if (c == 'e')
		return (6);
	if (c == 'E')
		return (7);
	if (c == 'f')
		return (8);
	if (c == 'F')
		return (9);
	if (c == 'g')
		return (10);
	return (index2(c));
}
