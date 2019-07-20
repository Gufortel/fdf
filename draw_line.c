/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:34:27 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/20 14:52:39 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	pixel(t_fdf *p, int x, int y, int color)
{
	set_pixel(p, x, y, color);
}

int		sign(double deltay)
{
	if (deltay < 0.0)
	{
		return (-1);
	}
	return (1);
}

void	drawx(t_fdf *p)
{
	double deltay;
	double delta;
	double err;	
	int x;
	int y;

	err = 0.0;
	deltay = p->y1 - p->y0;
	delta = fabs(deltay / (p->x1 - p->x0));
	y = p->y0;
	x = p->x0;
	while (x < p->x1 || x > p->x1)
	{
		pixel(p, x, y, p->color);
		err += delta;
		if (err >= 0.5)
		{
			y = y + sign(deltay) * 1;
			err += -1.0;
		}
		x += sign(p->x1 - p->x0);
	}
}

void	drawy(t_fdf *p)
{
	double deltay;
	double delta;
	double err;	
	int x;
	int y;

	err = 0.0;
	deltay = p->x1 - p->x0;
	delta = fabs(deltay / (p->y1 - p->y0));
	y = p->y0;
	x = p->x0;
	while (y < p->y1 || y > p->y1)
	{
		pixel(p, x, y, p->color);
		err += delta;
		if (err >= 0.5)
		{
			x = x + sign(deltay) * 1;
			err += -1.0;
		}
		y += sign(p->y1 - p->y0);
	}
}

void	draw(t_fdf *p)
{
	if (abs(p->x1 - p->x0) >= abs(p->y1 - p->y0))
		drawx(p);
	else
		drawy(p);
}