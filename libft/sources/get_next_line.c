/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:07:00 by sait-ben          #+#    #+#             */
/*   Updated: 2016/12/14 11:12:50 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		lecture(t_l *struc, int fd, char **line)
{
	struc->ret = read(fd, struc->buff, BUFF_SIZE);
	if (struc->ret == 0 && ft_strchr(struc->tmp, '\n') == NULL)
	{
		*line = struc->tmp;
		return (0);
	}
	if (struc->ret == -1)
		return (-1);
	struc->buff[struc->ret] = '\0';
	struc->s = struc->tmp;
	struc->tmp = ft_strjoin(struc->tmp, struc->buff);
	free(struc->s);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	t_l			struc;
	static char *rest = NULL;

	if (!line)
		return (-1);
	*line = NULL;
	if (rest)
	{
		struc.tmp = ft_strdup(rest);
		ft_strdel(&rest);
	}
	else
		struc.tmp = ft_strnew(0);
	while (ft_strchr(struc.tmp, '\n') == NULL)
	{
		if (lecture(&struc, fd, line) == 0 || struc.ret == -1)
			return ((ft_strlen(struc.tmp) > 0) + struc.ret);
	}
	rest = ft_strdup(ft_strchr(struc.tmp, '\n') + 1);
	struc.len = ft_strlen(struc.tmp) - ft_strlen(rest);
	*line = ft_strsub(struc.tmp, 0, struc.len - 1);
	free(struc.tmp);
	return (1);
}
