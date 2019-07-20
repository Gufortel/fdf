/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:00:11 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/20 22:49:43 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	count_line(char *file, t_fdf *p)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed open file\n");
		exit(-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		count++;
		if (line)
			free(line);
	}
	p->size_mapx = count;
	close(fd);
}

void	fill_tab(t_fdf *p, char **tab, int i)
{
	int		j;

	j = 0;
	while (tab[j])
		j++;
	if (p->size_mapy != j && p->size_mapy != 0)
	{
		ft_printf("Wrong map");
		exit(-1);
	}
	p->size_mapy = j;
	p->matrix[i] = (int*)ft_memalloc(sizeof(int) * j + 1);
	j = 0;
	while (tab[j])
	{
		p->matrix[i][j] = ft_atoi(tab[j]);
		j++;
	}
}

void	delete_tab(char **tab)
{
	int		j;

	j = 0;
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

void	recup(char *file, t_fdf *p, int i)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed open file\n");
		exit(-1);
	}
	count_line(file, p);
	p->matrix = (int**)ft_memalloc(sizeof(int*) * p->size_mapx + 1);
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		fill_tab(p, tab, i);
		delete_tab(tab);
		if (line)
			free(line);
		i++;
	}
	p->zoom_init = (p->size_mapy > p->size_mapx) ?
	p->size_mapy * 1.2 : p->size_mapx * 1.2;
	p->zoom = p->zoom_init;
	close(fd);
}
