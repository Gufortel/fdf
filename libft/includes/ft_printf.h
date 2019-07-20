/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 07:24:39 by gufortel          #+#    #+#             */
/*   Updated: 2019/02/12 20:15:24 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
**	Pour colorer le text:
**	{LA COULEUR EN MAJUSCULE}
*/

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define PURPLE		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define GREY		"\033[1;37m"
# define B_BLACK	"\033[1;40m"
# define B_RED		"\033[1;41m"
# define B_GREEN	"\033[1;42m"
# define B_YELLOW	"\033[1;43m"
# define B_BLUE		"\033[1;44m"
# define B_PURPLE	"\033[1;45m"
# define B_CYAN		"\033[1;46m"
# define B_GREY		"\033[1;47m"
# define LIGHT		"\033[1;m"
# define DARK		"\033[2;m"
# define ITALIC		"\033[3;m"
# define UNDERLINE	"\033[4;m"
# define CLEAR		"\033[H\033[2J"
# define DEFAULT	"\033[0;m"

/*
**	g_len = taille de la chaine finale
**	afficher pour le retour de ft_printf
**	et l'allocation du buffer;
*/

int					g_exit;
int					g_nbvar;
int					g_len;

/*
**  stool 0 = rien
**  stool 1 = h
**  stool 2 = hh
**  stool 3 = l
**  stool 4 = ll
**  stool 5 = L
**  stool 6 = H
**  stool 7 = j
**  stool 8 = z
*/

/*
** index prit en compte :
** index 	= d fait/
** index    = D fait/
** index 	= i fait/
** index 	= o fait/
** index 	= O fait/
** index 	= u fait/
** index 	= U	fait/
** index 	= x fait/
** index 	= X fait/
** index 	= e
** index 	= E
** index 	= f
** index 	= F
** index 	= g
** index 	= G
** index 	= a
** index 	= A
** index 	= c fait/
** index 	= C fait/
** index 	= s fait/
** index 	= S fait/
** index 	= p fait/
** index 	= n fait/
** index	= m	fait/
** index	= % fait/
** index	= b fait/
** index	= r fait/
** index	= k fait/
** index	= K fait/
*/

/*
** convertion bonus :
** b = transforme en binaire;
** r = affiche les caractere non imprimable;
** k = affiche sous forme de liste un chaine de caractere;
** K = affiche une date avec l'int envoye/ 10122021 = 10/12/2012;
*/

/*
** bonus :
** couleurs
** perror
** vprintf
** syntax
** couleur fond
*/

/*
**	s		: type de struct
**	die		: #
**	zero	: 0
**	less	: -
**	more	: +
**	spc		: ' '
**	acco	: '
**	with	: largeur de champ
**	exact	: precision
**	stool	:  Modificateur de longeur
**	data	: stockage donner non transforme
**	index	: type de donnee
**	str		: chaine a afficher deja traiter
*/
typedef struct		s_var
{
	int					s;
	int					die;
	int					zero;
	int					less;
	int					more;
	int					spc;
	int					width;
	int					exact;
	int					stool;
	int					acco;
	void				*data;
	char				*str;
	char				index;
	struct s_var		*next;
}					t_var;

int					ft_printf(const char *format, ...);
t_var				*new_t_var(void *data, char *str);
t_var				*push_t_var(t_var **begin_list, void *data, char *str);
t_var				*chkdi(const char *str, t_var **ptr);
t_var				*schtypnorm(va_list ap, const char *str, t_var **ptr,
					int *nbvar);
void				*arg(int nb, va_list ap);
void				treatarg(t_var **lst);
void				arg2(t_var **lst);
void				arg3(t_var **lst);
void				set_color(const char *str, int *j, int *i, t_var **ptr);
void				del_t_var_elem(t_var *p);
int					del_t_var_elem_exit(t_var *p);
void				del_t_var(t_var **begin_list);
void				parse2(t_var **lst, char *str, va_list ap);
void				parse2norme(t_var *ptr, char *str, int *i, int *j);
void				parsenorm(t_var **lst, char *str, va_list ap, int *i);
void				argo(t_var **lst, int base);
int					argxnorm(t_var **lst, char *tmp);
void				argc(t_var **lst);
void				argcc(t_var **lst);
void				args(t_var **lst);
void				argss(t_var **lst);
int					index1(char c);
int					parse(t_var **ptr, char *str, va_list ap);
int					wstring(wchar_t wstr, char *str, int i, int size);
void				ft_mal_loc(void);
void				convd(t_var **lst);
void				widthdmore(long long int b, int i, t_var **lst, char *data);
void				argerrno(t_var **lst);
void				unprint(t_var **lst);
void				argbi(t_var **lst);
void				argdi(t_var **lst);
void				argnb(t_var **lst);
void				ft_printfnorm(int *i, int *j, t_var **ptr);
int					printbuffer(t_var *ptr);
void				printfcondition1(int *i, int *j,
					const char *format, t_var **ptr);
void				printfcondition2(int *i, int *j,
					const char *format, t_var *ptr);
void				elsenorme(const char *format, int *j, int *i, t_var **ptr);
void				contxnorm(char *str, t_var *p, t_var **lst);
char				*argo_flag(t_var **lst, char *str);
void				argo_exac(t_var **lst, char *str);
void				parsenorm3(t_var **lst, va_list ap);
void				arglst(t_var **lst);
void				argdate(t_var **lst);
int					vft_printf(char **str, int *nbr, const char *format, ...);
int					vprintbuffer(t_var *ptr, char **str, int *nbr);
int					chroccu(char *str);
void				*arg(int nb, va_list ap);
t_var				*schtyp(va_list ap, const char *str, t_var **ptr,
					int *nbvar);
t_var				*elem(const char *str, int *j, t_var **ptr, va_list ap);
void				elsenorme(const char *format, int *j, int *i, t_var **ptr);

/*
** Fonction de developpement/
*/

void				printlist(t_var *pa);
void				printout(t_var *p);
#endif
