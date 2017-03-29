/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:49:10 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/21 13:31:39 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			int_len(long int n)
{
	long int i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				len;
	long int		k;
	int				sign;

	k = n;
	sign = 0;
	if (k < 0)
		sign = 1;
	if (k < 0)
		k *= -1;
	len = int_len(k) + sign;
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	str[len] = '\0';
	if (k == 0)
		str[0] = '0';
	while (len != 0)
	{
		str[len-- - 1] = (k % 10) + 48;
		k = (k / 10);
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
