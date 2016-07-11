/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 08:56:57 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 08:56:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void		load(t_string *t)
{
	if (ft_strlen(t->sub_num) == 0 || !ft_strcmp(t->sub_num, "."))
	{
		t->space = 0;
		t->zero = 0;
		return ;
	}
	t->space = ft_atoi(t->sub_num);
	if (t->space == 0 && t->sub_num[0] == '.')
		t->zero = ft_atoi(t->sub_num + 1);
	else
		t->zero = ft_atoi(t->sub_num + ft_nbrlen(t->space) + 1);
}

int		ft_max(int min, int nbr)
{
	if (nbr < min)
		return (min);
	return (nbr);
}

static void		s_alt(t_string *t)
{
	if ((t->sub_flags & SUB_SHARP) && t->base == 16)
	{
		add_char(t, L'0');
		add_char(t, t->zero);
	}
	if (ft_atoi(t->tmp) != 0 && (t->sub_flags & SUB_SHARP) && t->base == 8)
	{
		add_char(t, '0');
		t->space -= 1;
	}
}

static void		signe(t_string *t)
{
	if (((t->sub_flags & SUB_INF) && t->base == 10)
		|| (t->is_negative && t->base == 10))
		add_char(t, '-');
	else if ((t->sub_flags & SUB_SUP) && t->base == 10)
		add_char(t, '+');
	else if ((t->sub_flags & SUB_SPACE) && t->base == 10)
		add_char(t, ' ');
}

static void		if_flags(t_string *t)
{
	if ((t->sub_flags & SUB_INF) && t->base == 10)
		t->space -= 1;
	else if ((t->sub_flags & SUB_SUP) && t->base == 10)
		t->space -= 1;
	else if ((t->sub_flags & SUB_SPACE) && t->base == 10)
		t->space -= 1;
	if ((t->sub_flags & SUB_SHARP) && t->base == 16)
		t->space -= 2;
	if (t->zero <= (short)ft_strlen(t->tmp) && (t->sub_flags & SUB_SHARP) && t->base == 8)
		t->space -= 1;
}

static void		not_left(t_string *t)
{
	t->space -= ft_strlen(t->tmp) + t->zero;
	if_flags(t);
	signe(t);
	if (t->pad == ' ')
	{
		fill_character(t, ' ');
		t->space = 0;
	}
	/*if (t->pad == ' ' && (t->sub_flags & SUB_ZERO))
	{
		fill_character(t, '0');
		t->space = 0;
	}*/
	s_alt(t);
	t->space += t->zero;
	fill_character(t, '0');
	add_string(t, t->tmp, 2);
}

void		precision(t_string *t)
{
	load(t);
	if (t->zero < 0)
		t->zero = 1;
	else
		t->pad = ' ';
	t->zero = ft_max(0, t->zero - ft_strlen(t->tmp));
	if (t->left == 0)
		not_left(t);
	else
		process_left(t);
}
