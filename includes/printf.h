/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:11:36 by jguyet            #+#    #+#             */
/*   Updated: 2016/03/17 14:12:48 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

int			ft_printf(const char *s, ...);

# ifdef PRINTF_PROG

typedef struct		s_string
{
	char			*s;
	va_list			list;
	unsigned int	res;
	short			sub_flags;
	char			*sub_num;
}					t_string;

#  define FLAG string->s + (i + 1)
#  define SUB_SHARP 1024
#  define SUB_ZERO 2048
#  define SUB_INF 4096
#  define SUB_SUP 8192
#  define DELIMITER '%'
/*
 **			handler.c
 */
int			parse_flags(t_string *string, int i);
/*
 *			sub_flags.c
 */
int			sub_flags(t_string *string, int i);
/*
 *			Total_flags :
 */
int			flag_ld(t_string *string, int i);
int			flag_d(t_string *string, int i);
int			flag_s(t_string *string, int i);
int			flag_c(t_string *string, int i);
int			flag_x(t_string *string, int i);
int			flag_X(t_string *string, int i);
# endif
#endif
