/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 15:21:45 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/23 11:39:25 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft.h"

int		len_count(intmax_t value, int base)
{
	int len;

	len = 0;
	if (value <= 0)
	{
		len = 1;
		value = value * -1;
	}
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(intmax_t value, int base)
{
	static char rep[] = "0123456789abcdef";
	char		*buff;
	intmax_t	num;
	int			len;
	int			i;

	len = len_count(value, base);
	buff = ft_strnew(len);
	i = len;
	buff[i] = '\0';
	num = value;
	if (value < 0 && base == 10)
		value = value * -1;
	if (value == 0)
		buff[--i] = rep[0];
	while (value != 0)
	{
		buff[--i] = rep[value % base];
		value = value / base;
	}
	if (num < 0 && base == 10)
		buff[--i] = '-';
	return (buff);
}
