/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argerrno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:31:04 by gufortel          #+#    #+#             */
/*   Updated: 2018/04/25 05:36:50 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/ft_errno.h"
#include <errno.h>

void		argerrno5(char **tab)
{
	tab[88] = FT_ENOTSOCK;
	tab[89] = FT_EDESTADDRREQ;
	tab[90] = FT_EMSGSIZE;
	tab[91] = FT_EPROTOTYPE;
	tab[92] = FT_ENOPROTOOPT;
	tab[93] = FT_EPROTONOSUPPORT;
	tab[94] = FT_ESOCKTNOSUPPORT;
	tab[95] = FT_EOPNOTSUPP;
	tab[96] = FT_EPFNOSUPPORT;
	tab[97] = FT_EAFNOSUPPORT;
	tab[98] = FT_EADDRINUSE;
	tab[99] = FT_EADDRNOTAVAIL;
	tab[100] = FT_ENETDOWN;
	tab[101] = FT_ENETUNREACH;
	tab[102] = FT_ENETRESET;
	tab[103] = FT_ECONNABORTED;
	tab[104] = FT_ECONNRESET;
	tab[105] = FT_ENOBUFS;
	tab[106] = FT_EISCONN;
	tab[107] = FT_ENOTCONN;
	tab[108] = FT_ESHUTDOWN;
	tab[109] = FT_ETOOMANYREFS;
	tab[110] = FT_ETIMEDOUT;
	tab[111] = FT_ECONNREFUSED;
	argerrno6(tab);
}

void		argerrno4(char **tab)
{
	tab[64] = FT_ENONET;
	tab[65] = FT_ENOPKG;
	tab[66] = FT_EREMOTE;
	tab[67] = FT_ENOLINK;
	tab[68] = FT_EADV;
	tab[69] = FT_ESRMNT;
	tab[70] = FT_ECOMM;
	tab[71] = FT_EPROTO;
	tab[72] = FT_EMULTIHOP;
	tab[73] = FT_EDOTDOT;
	tab[74] = FT_EBADMSG;
	tab[75] = FT_EOVERFLOW;
	tab[76] = FT_ENOTUNIQ;
	tab[77] = FT_EBADFD;
	tab[78] = FT_EREMCHG;
	tab[79] = FT_ELIBACC;
	tab[80] = FT_ELIBBAD;
	tab[81] = FT_ELIBSCN;
	tab[82] = FT_ELIBMAX;
	tab[83] = FT_ELIBEXEC;
	tab[84] = FT_EILSEQ;
	tab[85] = FT_ERESTART;
	tab[86] = FT_ESTRPIPE;
	tab[87] = FT_EUSERS;
	argerrno5(tab);
}

void		argerrno3(char **tab)
{
	tab[40] = FT_ELOOP;
	tab[41] = FT_EWOULDBLOCK;
	tab[42] = FT_ENOMSG;
	tab[43] = FT_EIDRM;
	tab[44] = FT_ECHRNG;
	tab[45] = FT_EL2NSYNC;
	tab[46] = FT_EL3HLT;
	tab[47] = FT_EL3RST;
	tab[48] = FT_ELNRNG;
	tab[49] = FT_EUNATCH;
	tab[50] = FT_ENOCSI;
	tab[51] = FT_EL2HLT;
	tab[52] = FT_EBADE;
	tab[53] = FT_EBADR;
	tab[54] = FT_EXFULL;
	tab[55] = FT_ENOANO;
	tab[56] = FT_EBADRQC;
	tab[57] = FT_EBADSLT;
	tab[58] = FT_EDEADLOCK;
	tab[59] = FT_EBFONT;
	tab[60] = FT_ENOSTR;
	tab[61] = FT_ENODATA;
	tab[62] = FT_ETIME;
	tab[63] = FT_ENOSR;
	argerrno4(tab);
}

void		argerrno2(char **tab)
{
	tab[16] = FT_EBUSY;
	tab[17] = FT_EEXIST;
	tab[18] = FT_EXDEV;
	tab[19] = FT_ENODEV;
	tab[20] = FT_ENOTDIR;
	tab[21] = FT_EISDIR;
	tab[22] = FT_EINVAL;
	tab[23] = FT_ENFILE;
	tab[24] = FT_EMFILE;
	tab[25] = FT_ENOTTY;
	tab[26] = FT_ETXTBSY;
	tab[27] = FT_EFBIG;
	tab[28] = FT_ENOSPC;
	tab[29] = FT_ESPIPE;
	tab[30] = FT_EROFS;
	tab[31] = FT_EMLINK;
	tab[32] = FT_EPIPE;
	tab[33] = FT_EDOM;
	tab[34] = FT_ERANGE;
	tab[35] = FT_FREDEADLK;
	tab[36] = FT_ENAMETOOLONG;
	tab[37] = FT_ENOLCK;
	tab[38] = FT_ENOSYS;
	tab[39] = FT_ENOTEMPTY;
	argerrno3(tab);
}

void		argerrno(t_var **lst)
{
	char	**tab;
	t_var	*p;

	p = *lst;
	tab = (char**)ft_memalloc(sizeof(char*) * 133);
	tab[1] = FT_EPERM;
	tab[2] = FT_ENOENT;
	tab[3] = FT_ESRCH;
	tab[4] = FT_EINTR;
	tab[5] = FT_EIO;
	tab[6] = FT_ENXIO;
	tab[7] = FT_E2BIG;
	tab[8] = FT_ENOEXEC;
	tab[9] = FT_EBADF;
	tab[10] = FT_ECHILD;
	tab[11] = FT_EAGAIN;
	tab[12] = FT_ENOMEM;
	tab[13] = FT_EACCES;
	tab[14] = FT_EFAULT;
	tab[15] = FT_ENOTBLK;
	argerrno2(tab);
	p->str = ft_strdup(tab[errno]);
	free(tab);
}
