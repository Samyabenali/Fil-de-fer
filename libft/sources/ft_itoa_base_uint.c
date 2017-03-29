/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:38:22 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/21 13:25:27 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ulen_count(uintmax_t value, int base)
{
	int len;

	len = 0;
	if (value == 0)
		len = 1;
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base_uint(uintmax_t value, int base)
{
	static char rep[] = "0123456789abcdef";
	char		*buff;
	uintmax_t	num;
	int			len;
	int			i;

	len = ulen_count(value, base);
	buff = ft_strnew(len + 1);
	i = len;
	buff[i] = '\0';
	num = value;
	if (value == 0)
		buff[--i] = rep[0];
	while (value != 0)
	{
		buff[--i] = rep[value % base];
		value = value / base;
	}
	return (buff);
}
