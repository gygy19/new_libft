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
	while (i < string->res)
	{
		write(1, string->new + i, 1);
		i++;
	}
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
	va_start(string->list, (char*)s);
	parse_flags(string, 0);
	*ptr = string->new;
	va_end(string->list);
	return (string->res);
}
