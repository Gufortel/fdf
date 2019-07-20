/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 03:54:39 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/10 08:02:54 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			tmp;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = (unsigned int)-n;
	}
	else
		nb = (unsigned int)n;
	if (nb > 10)
		ft_putnbr_fd(nb / 10, fd);
	tmp = nb % 10 + '0';
	write(fd, &tmp, 1);
}
