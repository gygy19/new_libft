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

int			parse_ptr(t_string *string, int i)
{
	int		l;
	char	*sptrs;

	sptrs = ft_strdup("scdixXCSpDoOuU");
	l = -1;
	while (sptrs[++l])
		if (sptrs[l] == string->s[i + 1])
			return (get_ptr_function(string, i, string->ptrs[l]));
	if (!ft_strncmp("%", FLAG, 1))
		return (conv_purcent(string, i));
	else if (string->sub_num != NULL)
	{
		string->tmp = ft_strndup(string->s + i + 1, 1);
		string->is_big = 5;
		add_conv_string(string, string->tmp);
		return (i + 1);
	}
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
	string->sub_num = NULL;
	string->is_big = 0;
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
