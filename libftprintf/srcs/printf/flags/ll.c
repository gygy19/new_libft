/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:18:24 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:18:26 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

char		*flag_ll(t_string *string, short base)
{
	long long int			tmp;

	tmp = get_long_long_int(string);
	if (tmp < 0)
	{
		tmp = -tmp;
		string->is_negative = 1;
	}
	if (base == 8)
		return (ft_itoabase(tmp, "01234567"));
	else if (base == 10)
		return (ft_itoa(tmp));
	else if (base == 16)
		return (ft_itoabase(tmp, "0123456789abcdef"));
	else if (base == 32)
		return (ft_itoabase(tmp, "0123456789ABCDEF"));
	return (NULL);
}

char		*flag_ull(t_string *string, short base)
{
	unsigned long long int	tmp;

	tmp = get_ulong_long_int(string);
	string->is_negative = 0;
	if (base == 8)
		return (ft_uitoabase(tmp, "01234567"));
	else if (base == 10)
		return (ft_uitoa(tmp));
	else if (base == 16)
		return (ft_uitoabase(tmp, "0123456789abcdef"));
	else if (base == 32)
		return (ft_uitoabase(tmp, "0123456789ABCDEF"));
	return (NULL);
}
