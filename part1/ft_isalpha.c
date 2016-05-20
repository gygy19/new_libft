/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:25:50 by jguyet            #+#    #+#             */
/*   Updated: 2015/11/25 17:25:52 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	else if (c <= 'z' && c >= 'a')
		return (1);
	return (0);
}
