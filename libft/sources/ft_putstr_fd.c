/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:51:51 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/21 15:27:55 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putstr_fd(char const *s, int fd)
{
	int i;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], fd);
		i++;
	}
}
