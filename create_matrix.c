/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 22:03:32 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/20 14:44:56 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int		color(int z0, int z1)
{
	int		z;

	z = ((z0 + z1) / 2);
	//return (255 + (abs(z) * ((16777215 / 1000))));
	if (z < 0)
	{
		return (39423);
	}
	if (z >= 0 && z < 100)
	{
		return (39168);
	}
	if (z > 100)
	{
		return (10053171);
	}
	return (0);
}

int		treat_project(double z, int x_y, t_fdf *p)
{
	double x;
	double x_rotate;
	double y_rotate;

	x_rotate = p->i_matrix;
	z = p->z_val * z;
	y_rotate = ((cos(p->r_x) * p->j_matrix) - (sin(p->r_x) * z));
	z = ((sin(p->r_x) * p->j_matrix) + (cos(p->r_x) * z));
	x_rotate = ((cos(p->r_y) * x_rotate) + (sin(p->r_y) * z));
	z = (-(sin(p->r_y) * x_rotate) + (cos(p->r_y) * z));
	x = 0.0;
	x = p->tab[x_y][0] * x_rotate;
	x += p->tab[x_y][1] * y_rotate;
	x += p->tab[x_y][2] * z;
	x += (x_max / p->zoom) * x;
	x += (x_y == 0) ? p->axe_x : p->axe_y;
	return (x);
}

void	norme_1(t_fdf *p)
{
	p->j_matrix = p->j_matrix + 1;
	p->x1 = treat_project(p->matrix[p->j_matrix][p->i_matrix], 0, p);
	p->y1 = treat_project(p->matrix[p->j_matrix][p->i_matrix], 1, p);
	p->color = color(p->matrix[p->j_matrix][p->i_matrix], p->matrix[p->j_matrix - 1][p->i_matrix]);
	p->j_matrix = p->j_matrix - 1;
	draw(p);
}

void	norme_2(t_fdf *p)
{
	p->i_matrix = p->i_matrix + 1;
	p->x1 = treat_project(p->matrix[p->j_matrix][p->i_matrix], 0, p);
	p->y1 = treat_project(p->matrix[p->j_matrix][p->i_matrix], 1, p);
	p->color = color(p->matrix[p->j_matrix][p->i_matrix], p->matrix[p->j_matrix][p->i_matrix - 1]);
	p->i_matrix = p->i_matrix - 1;
	draw(p);
}

void	create_image(t_fdf *p)
{
	p->img = mlx_new_image(p->mlx, x_max, y_max);
	mlx_clear_window(p->mlx, p->win);
	p->j_matrix = 0;
	while(p->j_matrix < p->size_mapx)
	{
		p->i_matrix = 0;
		while(p->i_matrix < p->size_mapy)
		{
			p->x0 = treat_project(p->matrix[p->j_matrix][p->i_matrix], 0, p);
			p->y0 = treat_project(p->matrix[p->j_matrix][p->i_matrix], 1, p);
			if (p->j_matrix + 1 < p->size_mapx)
				norme_1(p);
			if(p->i_matrix + 1 < p->size_mapy)
				norme_2(p);
			p->i_matrix = p->i_matrix + 1;
		}
		p->j_matrix = p->j_matrix + 1;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}