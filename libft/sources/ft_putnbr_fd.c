/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:02:00 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/18 12:10:24 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void			ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static unsigned int	convert(int n)
{
	unsigned int k;

	if (n < 0)
		k = -n;
	else
		k = n;
	return (k);
}

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int k;

	if (n < 0)
		ft_putchar_fd('-', fd);
	k = convert(n);
	if (k >= 10)
		ft_putnbr_fd((k / 10), fd);
	ft_putchar_fd((k % 10) + 48, fd);
}
