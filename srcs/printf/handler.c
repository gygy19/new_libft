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

int			parse_one(t_string *string, int i)
{
	if (!ft_strncmp("s", FLAG, 1))
		i = flag_s(string, i);
	else if (!ft_strncmp("ld", FLAG, 2))
		i = flag_ld(string, i);
	else if (!ft_strncmp("c", FLAG, 1))
		i = flag_c(string, i);
	else if (!ft_strncmp("d", FLAG, 1))
		i = flag_d(string, i);
	else if (!ft_strncmp("x", FLAG, 1))
		i = flag_x(string, i);
	else if (!ft_strncmp("X", FLAG, 1))
		i = flag_X(string, i);
	return (i);
}

int			parse_two(t_string *string, int i)
{
	(void)string;
	return (i);
}

int			parse_flags(t_string *string, int i)
{
	int save;

	if (!string->s[i])
		return (0);
	string->sub_num = NULL;
	save = i;
	while (string->s[i] && string->s[i] != DELIMITER)
	{
		i++;
		string->res++;
	}
	//if (i > save)
	//	ft_putnstr(string->s + save, i - save);
	if (string->s[i] && string->s[i] == DELIMITER && string->s[i + 1])
	{
		save = i + 1;
		i = sub_flags(string, i);
		if ((i = parse_one(string, i)) == save)
			if ((i = parse_two(string, i)) == save)
			{
			}
	}
	else
		return (0);
	return (parse_flags(string, i + 1));
}