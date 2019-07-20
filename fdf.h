/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:11:00 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/20 14:52:44 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "./libft/includes/libft.h"
#include "./minilibx_macos/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define x_max 1430
#define y_max 800

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	double		tab[2][3];
	int			pro;
	int			**matrix;
	int			size_mapx;
	int			size_mapy;
	int			zoom;
	int			axe_x;
	int			axe_y;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	double		z_val;
	int			color;
	double		r_x;
	double		r_y;
	int			i_matrix;
	int			j_matrix;
}				t_fdf;

t_fdf				*createfdf(int x, int y);
void				draw(t_fdf *p);
void				drawx(t_fdf *p);
void				drawy(t_fdf *p);
void				pixel(t_fdf *p, int x, int y, int color);
void				recup(char *file, t_fdf *p);
void				create_matrix(t_fdf *p);
void				create_image(t_fdf *p);
void				set_pixel(t_fdf *p, int x, int y, int color);
void				iso(t_fdf *p);
void				par(t_fdf *p);

#endif