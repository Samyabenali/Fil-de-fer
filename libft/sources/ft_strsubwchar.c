/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubwchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:43:15 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/18 13:18:36 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "printf.h"

size_t	wwstrlen(wchar_t *str, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	j = 0;
	ret = 0;
	while (ret < len && str[j])
	{
		if (str[j] <= 0x7F)
			i = 1;
		else if (str[j] <= 0x7FF)
			i = 2;
		else if (str[j] <= 0xFFFF)
			i = 3;
		else if (str[j] <= 0x10FFFF)
			i = 4;
		ret += i;
		j++;
		if (ret == len)
			return (ret);
	}
	return (len - (4 - i));
}

char	*ft_strsubwchar(char *s, int start, t_options *opt)
{
	size_t	wlen;

	(void)start;
	if (!s)
		return (NULL);
	wlen = wwstrlen(opt->wbuff, opt->precision);
	s[wlen] = '\0';
	return (s);
}
