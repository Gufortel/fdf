/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:10:50 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/20 15:04:01 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	key_hook2(int keycode, t_fdf *p)
{
	if (keycode == 2)
		p->axe_x += 50;
	else if (keycode == 0)
		p->axe_x -= 50;
	else if (keycode == 1)
		p->axe_y += 50;
	else if (keycode == 13)
		p->axe_y -= 50;
	else if (keycode == 3)
		iso(p);
	else if (keycode == 5)
		par(p);
	else if (keycode == 269 && p->zoom != 1)
		p->zoom *= 0.5;
}

int		key_hook(int keycode, void *params)
{
	t_fdf *p;
	p = params;
	if (keycode == 53)
		exit(42);
	if (keycode == 43 && p->pro == 0)
		p->z_val += 0.1;
	else if (keycode == 47 && p->pro == 0)
		p->z_val -= 0.1;
	else if (keycode == 125 && p->pro == 0)
		p->r_x += 0.1;
	else if (keycode == 126 && p->pro == 0)
		p->r_x -= 0.1;
	else if (keycode == 123 && p->pro == 0)
		p->r_y += 0.1;
	else if (keycode == 124 && p->pro == 0)
		p->r_y -= 0.1;
	else if (keycode == 258)
		p->zoom *= 2;
	else
		key_hook2(keycode, p);
	create_image(p);
	return (1);
}

int main (int ac, char **av)
{
	t_fdf	*p;
	av += 0;
	p = createfdf(x_max, y_max);
	if (ac != 2)
	{
		ft_printf("Wrong Arguments");
		return(-1);
	}
	recup(av[1], p);
	create_matrix(p);
	create_image(p);
	mlx_key_hook(p->win, key_hook, p);
	mlx_loop(p->mlx);
	while(1);
	return (0);
}