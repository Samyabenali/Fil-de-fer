/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:39:37 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/18 12:09:35 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static unsigned int	convert(int n)
{
	unsigned int k;

	if (n < 0)
		k = -n;
	else
		k = n;
	return (k);
}

void				ft_putnbr(int n)
{
	unsigned int b;

	if (n < 0)
		ft_putchar('-');
	b = convert(n);
	if (b >= 10)
		ft_putnbr(b / 10);
	ft_putchar((b % 10) + 48);
}
