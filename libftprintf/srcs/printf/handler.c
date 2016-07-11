/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:11:11 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/17 16:11:12 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

int			inter(t_string *string, int i, int f(t_string*, int))
{
	return (f(string, i));
}

void		load_ptr_function(t_string *string)
{
	string->ptrs[s] = &conv_s;
	string->ptrs[c] = &conv_c;
	string->ptrs[d] = &conv_d;
	string->ptrs[i] = &conv_d;
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
}

int			parse_ptr(t_string *string, int i)
{
	int		l;
	char	*sptrs;

	sptrs = ft_strdup("scdixXCSpDoOuU");
	load_ptr_function(string);
	l = -1;
	while (sptrs[++l])
		if (sptrs[l] == string->s[i + 1])
			return (inter(string, i, string->ptrs[l]));
	if (!ft_strncmp("%", FLAG, 1) && (i = i + 1))
		add_char(string, '%');
	return (i);
}

int			select_converter_two(t_string *string, int i)
{
	if (!ft_strncmp("j", FLAG, 1) && (i = i + 1))
	{
		string->converter.type[0] = 'j';
		string->converter.type[1] = '\0';
	}
	else if (!ft_strncmp("z", FLAG, 1) && (i = i + 1))
	{
		string->converter.type[0] = 'z';
		string->converter.type[1] = '\0';
	}
	return (i);
}

int			select_converter_one(t_string *string, int i)
{
	if (!ft_strncmp("ll", FLAG, 2) && (i = i + 2))
	{
		string->converter.type[0] = 'l';
		string->converter.type[1] = 'l';
	}
	else if (!ft_strncmp("l", FLAG, 1) && (i = i + 1))
	{
		string->converter.type[0] = 'l';
		string->converter.type[1] = '\0';
	}
	else if (!ft_strncmp("hh", FLAG, 2) && (i = i + 2))
	{
		string->converter.type[0] = 'h';
		string->converter.type[1] = 'h';
	}
	else if (!ft_strncmp("h", FLAG, 1) && (i = i + 1))
	{
		string->converter.type[0] = 'h';
		string->converter.type[1] = '\0';
	}
	else
		return (select_converter_two(string, i));
	return (i);
}

void		restart_string_params(t_string *string)
{
	string->converter.type[0] = '\0';
	string->converter.type[1] = '\0';
	string->sub_flags = 0;
	string->space = 0;
	string->zero = 0;
	string->is_negative = 0;
}

int			parse_flags(t_string *string, int i)
{
	int save;

	if (!string->s[i])
		return (0);
	string->sub_num = NULL;
	save = i;
	while (string->s[i] && string->s[i] != DELIMITER)
		i++;
	if (i > save)
		add_string(string, ft_strndup(string->s + save, i - save), 3);
	if (string->s[i] && string->s[i] == DELIMITER && string->s[i + 1])
	{
		i = sub_flags(string, i);
		i = select_converter_one(string, i);
		save = i + 1;
		i = parse_ptr(string, i);
		restart_string_params(string);
		ft_strdel(&string->sub_num);
	}
	else
		return (0);
	return (parse_flags(string, i + 1));
}
