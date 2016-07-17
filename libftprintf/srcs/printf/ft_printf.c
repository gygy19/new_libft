/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:55:48 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/17 14:25:57 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include <printf.h>
#include <unistd.h>

static void	put_printf(t_string *string)
{
	unsigned int i;

	i = 0;
	if (BONUS)
	{
		printf_budle(string);
		ft_printf_center(string);
		modif_colors(string);
	}
	while (i < string->res)
	{
		write(1, string->new + i, 1);
		i++;
	}
}

void		load_ptr_function(t_string *string)
{
	string->ptrs[s] = &conv_s;
	string->ptrs[d] = &conv_d;
	string->ptrs[c] = &conv_c;
	string->ptrs[i] = &conv_i;
	string->ptrs[x] = &conv_x;
	string->ptrs[big_x] = &conv_big_x;
	string->ptrs[big_c] = &conv_big_c;
	string->ptrs[big_s] = &conv_big_s;
	string->ptrs[p] = &conv_p;
	string->ptrs[big_d] = &conv_big_d;
	string->ptrs[o] = &conv_o;
	string->ptrs[big_o] = &conv_big_o;
	string->ptrs[u] = &conv_u;
	string->ptrs[big_u] = &conv_big_u;
	string->ptrs[f] = &conv_f;
	string->ptrs[big_f] = &conv_f;
}

int			ft_printf(const char *s, ...)
{
	t_string	*string;

	if (!(string = (t_string *)malloc(sizeof(t_string))))
		return (-1);
	string->s = (char*)s;
	string->res = 0;
	string->new = ft_strnew(BUFFER);
	string->sub_num = NULL;
	load_ptr_function(string);
	va_start(string->list, (char*)s);
	parse_flags(string, 0);
	put_printf(string);
	ft_strdel(&string->new);
	va_end(string->list);
	return (string->res);
}

int			ft_asprintf(char **ptr, const char *s, ...)
{
	t_string	*string;

	if (!(string = (t_string *)malloc(sizeof(t_string))))
		return (-1);
	string->s = (char*)s;
	string->res = 0;
	string->new = ft_strnew(BUFFER);
	string->sub_num = NULL;
	load_ptr_function(string);
	va_start(string->list, (char*)s);
	parse_flags(string, 0);
	*ptr = string->new;
	va_end(string->list);
	return (string->res);
}
