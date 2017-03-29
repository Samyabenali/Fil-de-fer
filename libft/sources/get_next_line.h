/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:54:42 by sait-ben          #+#    #+#             */
/*   Updated: 2016/12/19 20:02:45 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 2

typedef struct	s_result
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	char		*s;
	int			len;
}				t_l;

int				get_next_line(const int fd, char **line);

#endif
