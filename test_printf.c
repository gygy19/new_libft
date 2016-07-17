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
	//int ret2 = printf(la%Sb%sc%Sl, Ll我l, l42l, Ll猫l);
	//int ret = ft_printf(la%Sb%sc%Sl, Ll我l, l42l, Ll猫l);
	//printf(l\n%d, %dl, ret, ret2);
	ft_printf("[%ls],lol\n", "lol\n");
	printf("[%ls,lol%d\n", "lol\n", 7);
	return (0);
}
