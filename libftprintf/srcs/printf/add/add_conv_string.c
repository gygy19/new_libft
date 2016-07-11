/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_conv_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:13:45 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/08 16:13:46 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		s_trunc(char **s, int length)
{
	int		size;
	int		index;
	char	*string;

	size = (length < 0) ? -length : length;
	string = ft_strnew(size);
	if (*s == NULL)
		return ;
	index = 0;
	*s = ft_strndup(*s, length);
}

void	fill_character(t_string *t, char c)
{
	while (t->space > 0)
	{
		add_char(t, c);
		t->space--;
	}
}

void			add_conv_string(t_string *t, char *s)
{
	size_t	len;

	load(t);
	len = ft_strlen(s);
	if (t->zero != 0)
	{
		s_trunc(&s, t->zero);
		len = ft_strlen(s);
	}
	else if (ft_strlen(t->sub_num) > 0 && t->sub_num[ft_strlen(t->sub_num) - 1] == '.')
	{
		s = ft_strnew(0);
		len = 0;
	}
	//ft_putstr(t->sub_num);
	if ((t->space -= len) < 0)
	{
		add_string(t, s, 0);
		return ;
	}
	if (t->left == 0)
		fill_character(t, t->pad);
	add_string(t, s, 0);
	if (t->left)
		fill_character(t, t->pad);
}

void			add_conv_char(t_string *t, char c)
{
	load(t);
	if ((t->space -= 1) < 0)
		return (add_char(t, c));
	if (t->left == 0)
		fill_character(t, t->pad);
	add_char(t, c);
	if (t->left)
		fill_character(t, t->pad);
}

void			add_conv_wchar(t_string *t, wchar_t c)
{
	load(t);
	if ((t->space -= 1) < 0)
		return (add_wchar(t, c));
	if (t->left == 0)
		fill_character(t, t->pad);
	add_wchar(t, c);
	if (t->left)
		fill_character(t, t->pad);
}
