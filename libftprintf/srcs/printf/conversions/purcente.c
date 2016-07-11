/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purcente.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:20:36 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:20:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		conv_process(t_string *string, char *tmp)
{
	//tmp = precision(string, tmp, 0, ft_strlen(tmp));
	add_conv_string(string, tmp);
}

int			conv_purcent(t_string *string, int i)
{
	conv_process(string, ft_strdup("%"));
	return (i + 1);
}
