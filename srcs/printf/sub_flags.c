/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:05:10 by jguyet            #+#    #+#             */
/*   Updated: 2016/03/18 14:05:12 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static int	sub(t_string *string, int i)
{
		while ((string->s[i + 1] && string->s[i + 1] == '#')
			|| (string->s[i + 1] && string->s[i + 1] == '-')
			|| (string->s[i + 1] && string->s[i + 1] == '+'))
		{
			if (string->s[i + 1] == '#' && !(string->sub_flags & SUB_SHARP))
				string->sub_flags += SUB_SHARP;
			else if (string->s[i + 1] == '-' && !(string->sub_flags & SUB_INF))
				string->sub_flags += SUB_INF;
			else if (string->s[i + 1] == '+' && !(string->sub_flags & SUB_SUP))
				string->sub_flags += SUB_SUP;
			i++;
		}
	return (i);
}

int			sub_flags(t_string *string, int i)
{
	int		u;
	char	*n;
	char	*tmp;

	string->sub_flags = 0;
	i = sub(string, i);
	u = i;
	tmp = ft_strnew(1);
	n = ft_strnew(1);
	while (string->s[u + 1] && string->s[u + 1] >= '0' && string->s[u + 1] <= '9')
	{
		tmp[0] = string->s[u + 1];
		n = ft_strjoin(n, tmp); 
		u++;
		if (string->s[u + 1] && string->s[u + 1] == '.')
		{
			n = ft_strjoin(n, "."); 
			u++;
		}
	}
	string->sub_num = n;
	i = u;
	i = sub(string, i);
	return (i);
}
