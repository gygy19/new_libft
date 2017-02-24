/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:32:16 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/13 16:29:11 by jguyet           ###   ########.fr       */
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
	int ret2 = printf("YOla%Sb%sc%Sl\n", "我", "4", "猫");
	int ret = ft_printf("LOla%Sb%sc%Sl\n", "我", "4", "猫");
	printf("%d, %d", ret, ret2);
	//ft_printf("[%ls],lol\n", "lol\n");
	//printf("[%ls,lol%d\n", "lol\n", 7);
	return (0);
}
