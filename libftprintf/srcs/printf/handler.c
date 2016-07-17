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

	sptrs = ft_strdup("sdcixXCSpDoOuUfF");
	l = -1;
	while (sptrs[++l])
		if (sptrs[l] == string->s[i + 1])
		{
			return (get_ptr_function(string, i, string->ptrs[l]));
		}
	if (!ft_strncmp("%", FLAG, 1))
	{
		return (conv_purcent(string, i));
	}
	else if (string->sub_num != NULL)
	{
		string->tmp = ft_strndup(string->s + i + 1, 1);
		string->is_big = 5;
		add_conv_string(string, string->tmp);
		return (i + 1);
	}
	return (i);
}

int			select_convert(t_string *string, int i)
{
	char	*lst;
	int		o;
	int		turn;
	int		ok;

	lst = ft_memcpy(ft_strnew(13), "lll\0z\0j\0hhh\0\0", 13);
	o = 0;
	turn = 100;
	ok = 0;
	while (lst[o])
	{
		if (SECURE && !ft_strncmp(lst + o, FLAG, lst[o + 1] == '\0' ? 1 : 2))
		{
			if (turn > o)
			{
				string->converter.type[0] = lst[o];
				string->converter.type[1] = lst[o + 1];
				turn = o;
				ok = 1;
			}
			i += lst[o + 1] == '\0' ? 1 : 2;
		}
		o += 2;
		if (o == 10 && ok != 0)
		{
			o = 0;
			ok = 0;
		}
	}
	ft_strdel(&lst);
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
	if (string->sub_num != NULL)
		ft_strdel(&string->sub_num);
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
		i = select_convert(string, i);
		save = i + 1;
		i = parse_ptr(string, i);
		restart_string_params(string);
	}
	else
		return (0);
	return (parse_flags(string, i + 1));
}
