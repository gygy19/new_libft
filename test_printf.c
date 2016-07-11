/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:32:16 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/17 15:33:16 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <libft.h>
#include <wchar.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int		main(void)
{
	ft_printf("%ld\n", -50);
	ft_printf("%d\n", 50);
	return (0);
}
