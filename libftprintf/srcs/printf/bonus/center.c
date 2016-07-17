/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 08:07:48 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/17 08:07:50 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static int	get_len_max(char *str)
{
	int i;
	int max_len;
	int len;

	i = 0;
	max_len = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (max_len < len)
				max_len = len;
			len = 0;
			i++;
			continue ;
		}
		len++;
		i++;
	}
	return (max_len);
}

static char	*get_midspace(int work, int len)
{
	char	*res;
	int		i;

	if (len == 0)
		return (NULL);
	len = (len - work) / 2;
	res = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		res[i] = ' ';
		i++;
	}
	return (res);
}

int			get_first_len(char *res)
{
	int len;
	int nbr;

	len = ft_strlen(res) - 1;
	nbr = 0;
	while (len > 0 && res[len] != '\n')
	{
		nbr++;
		len--;
	}
	return (nbr);
}

int			get_end_len(char *res)
{
	int i;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	return (i);
}

static char	*local_rp(char *str, int start, int end, t_string *string)
{
	char	*res;
	int		len;
	char	*center;
	char	*tmp;
	int		del_first;

	center = ft_strndup(str + start + 8, (end - start) - 8);
	len = get_len_max(str);
	res = ft_strndup(str, start);
	del_first = get_first_len(res);
	while (ft_strstr(center, "\n") != NULL)
	{
		tmp = ft_strstr(center, "\n") + 1;
		tmp = ft_strndup(center, (tmp - center) - 1);
		center = ft_strstr(center, "\n") + 1;
		res = ft_dstrjoin(res, get_midspace(ft_strlen(tmp) \
			+ del_first, len), 1);
		res = ft_dstrjoin(res, tmp, 1);
		res = ft_dstrjoin(res, get_midspace(ft_strlen(tmp) \
			+ del_first, len), 1);
		string->res += len - ft_strlen(tmp);
		res = ft_dstrjoin(res, "\n", 1);
		del_first = 0;
	}
	res = ft_dstrjoin(res, get_midspace(ft_strlen(center) \
		+ get_end_len(str + end + 9) + del_first, len), 1);
	res = ft_dstrjoin(res, center, 1);
	res = ft_dstrjoin(res, get_midspace(ft_strlen(center) \
		+ get_end_len(str + end + 9) + del_first, len), 1);
	res = ft_dstrjoin(res, str + end + 9, 1);
	string->res += len - ft_strlen(center);
	return (res);
}

static char	*ft_replace_center(char *str, t_string *string)
{
	int	i;
	int start;
	int end;

	i = 0;
	start = -1;
	end = -1;
	while (str[i])
	{
		if (start == -1 && !ft_strncmp(str + i, "{center}", 8))
			start = i;
		else if (start != -1 && !ft_strncmp(str + i, "{/center}", 9))
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
	return (ft_replace_center(str, string));
}

void		ft_printf_center(t_string *string)
{
	string->new = ft_replace_center(string->new, string);
}
