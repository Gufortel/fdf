/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:13:53 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/20 14:53:10 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_fdf *createfdf(int x, int y)
{
	t_fdf	*ptr;

	ptr = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	if (!ptr)
	{
		ft_printf("Wrong Malloc");
		exit(-1);
	}
	ptr->z_val = 1;
	ptr->zoom = 50;
	ptr->axe_x = 0;
	ptr->axe_y = 0;
	ptr->r_x = 0;
	ptr->r_y = 0;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, x, y, "Fdf");
	return (ptr);
}

void iso(t_fdf *p)
{
	p->tab[0][0] = (sqrt(2.0) / 2.0);
	p->tab[0][1] = -(sqrt(2.0) / 2.0);
	p->tab[0][2] = -(0);
	p->tab[1][0] = (1.0 / sqrt(6.0));
	p->tab[1][1] = (1.0 / sqrt(6.0));
	p->tab[1][2] = -(0.12);
	p->pro = 1;
	p->r_x = 0;
	p->r_y = 0;
	p->z_val = 1;
}

void	par(t_fdf *p)
{
	p->tab[0][0] = 1;
	p->tab[0][1] = 0;
	p->tab[0][2] = 0;
	p->tab[1][0] = 0;
	p->tab[1][1] = 1;
	p->tab[1][2] = 0;
	p->pro = 0;
	p->r_x = 0;
	p->r_y = 0;
	p->z_val = 1;
}

void	create_matrix(t_fdf *p)
{
	p->tab[0][0] = (sqrt(2.0) / 2.0);
	p->tab[0][1] = -(sqrt(2.0) / 2.0);
	p->tab[0][2] = -(0);
	p->tab[1][0] = (1.0 / sqrt(6.0));
	p->tab[1][1] = (1.0 / sqrt(6.0));
	p->tab[1][2] = -(0.12);
	p->pro = 1;
}