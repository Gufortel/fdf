/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:02:26 by gufortel          #+#    #+#             */
/*   Updated: 2018/07/10 01:12:41 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_power(const char *s, char **tab, char c, int k)
{
	int i;
	int j;

	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (1);
	j = i - 1;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (!(*tab = (char*)ft_memalloc(i - j)))
		return (0);
	while (++j < i)
		tab[0][k++] = s[j];
	tab[0][k] = '\0';
	if (s[i] == '\0')
		return (1);
	i = (ft_power(s + j, &tab[1], c, 0) < 1) ? 0 : 1;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**rtn;
	int		i;
	int		cpt;

	if (!s)
		return (NULL);
	cpt = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] && cpt++ > -4000)
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c)
			i++;
	}
	if (!(rtn = (char**)ft_memalloc((sizeof(char*) * cpt) + 1)))
		return (NULL);
	if (ft_power(s, rtn, c, 0) == 0)
		return (NULL);
	rtn[cpt] = NULL;
	return (rtn);
}
