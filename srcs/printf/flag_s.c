/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:17:30 by jguyet            #+#    #+#             */
/*   Updated: 2016/03/18 14:17:32 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

int			flag_s(t_string *string, int i)
{
	char	*tmp;

	tmp = NULL;
	tmp = va_arg(string->list, char*);
	if (tmp == NULL)
	{
		ft_putstr("(null)");
		return (i + 1);
	}
	ft_putstr(tmp);
	return (i + 1);
}
