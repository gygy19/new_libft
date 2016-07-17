/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 10:10:57 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/17 10:12:08 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static char	*get_tirer(int len)
{
	char	*tirer;
	int		i;

	tirer = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		tirer[i] = '-';
		i++;
	}
	tirer = ft_dstrjoin(tirer, "{/center}\n", 1);
	return (tirer);
}

static char	*local_rp(char *str, int start, int end, t_string *string)
{
	int		length;
	char	*center;
	char	*new;

	if (((end - start) % 2) == 0)
		length = ((end - start) - 4);
	else
		length = ((end - start) - 3);
	center = ft_strndup(str + start + 7, (end - start) - 7);
	new = ft_strdup("{center}");
	new = ft_dstrjoin(new, get_tirer(length), 0);
	new = ft_dstrjoin(new, "{center}| ", 0);
	new = ft_dstrjoin(new, center, 0);
	new = ft_dstrjoin(new, " |{/center}\n{center}", 0);
	new = ft_dstrjoin(new, get_tirer(length), 0);
	string->res += (length * 2) + 17 + 17 + 4 + 17;
	return (ft_replace(str, ft_dstrjoin(ft_strjoin("{budle}", \
		center), "{/budle}", 1), new));
}

static char	*ft_replace_budle(char *str, t_string *string)
{
	int	i;
	int start;
	int end;

	i = 0;
	start = -1;
	end = -1;
	while (str[i])
	{
		if (start == -1 && !ft_strncmp(str + i, "{budle}", 7))
			start = i;
		else if (start != -1 && !ft_strncmp(str + i, "{/budle}", 8))
		{
			end = i;
			break ;
		}
		i++;
	}
	if (start != -1 && end != -1 && (start + 8) != end)
		str = local_rp(str, start, end, string);
	else
		return (str);
	return (ft_replace_budle(str, string));
}

void		printf_budle(t_string *string)
{
	string->new = ft_replace_budle(string->new, string);
}
