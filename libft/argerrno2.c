/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argerrno2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:42:27 by gufortel          #+#    #+#             */
/*   Updated: 2018/01/09 19:41:15 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/ft_errno.h"

/*
**	Pour ajouter un code d'erreur.
*/

void		argerrno6(char **tab)
{
	tab[112] = FT_EHOSTDOWN;
	tab[113] = FT_EHOSTUNREACH;
	tab[114] = FT_EALREADY;
	tab[115] = FT_EINPROGRESS;
	tab[116] = FT_ESTALE;
	tab[117] = FT_EUCLEAN;
	tab[118] = FT_ENOTNAM;
	tab[119] = FT_ENAVAIL;
	tab[120] = FT_EISNAM;
	tab[121] = FT_EREMOTEIO;
	tab[122] = FT_EDQUOT;
	tab[123] = FT_ENOMEDIUM;
	tab[124] = FT_EMEDIUMTYPE;
	tab[125] = FT_ECANCELED;
	tab[126] = FT_ENOKEY;
	tab[127] = FT_EKEYEXPIRED;
	tab[128] = FT_EKEYREVOKED;
	tab[129] = FT_EKEYREJECTED;
	tab[130] = FT_EOWNERDEAD;
	tab[131] = FT_ENOTRECOVERABLE;
}
