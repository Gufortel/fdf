/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:20:36 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/17 13:54:06 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	set_pixel(t_fdf *p, int x, int y, int color)
{
	int				bpp;
	int				data;
	unsigned int	clr;
	clr = mlx_get_color_value(p->mlx, color);
	char *img = mlx_get_data_addr(p->img, &bpp, &data, &data);
	bpp /= 8;
	if (x < x_max && x > 0 && y < y_max && y > 0)
	{
		*(int *)(img + ((x + (y * x_max)) * bpp)) = clr;
	}
}