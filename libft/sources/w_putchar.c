/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_putchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 13:50:49 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/23 16:38:16 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ws_bis(wchar_t w)
{
	char	*src;

	if (w <= 0xFFFF)
	{
		src = ft_strnew(4);
		src[0] = (w >> 12) + 0xE0;
		src[1] = ((w >> 6) & 0x3F) + 0x80;
		src[2] = (w & 0x3F) + 0x80;
		src[3] = '\0';
	}
	else
	{
		src = ft_strnew(5);
		src[0] = (w >> 18) + 0xF0;
		src[1] = ((w >> 12) & 0x3F) + 0x80;
		src[2] = ((w >> 6) & 0x3F) + 0x80;
		src[3] = (w & 0x3F) + 0x80;
		src[4] = '\0';
	}
	return (src);
}

char	*ft_wputchar(wchar_t w)
{
	char	*src;

	if (w <= 0x7F)
	{
		src = ft_strnew(2);
		src[0] = w;
		src[1] = '\0';
	}
	else if (w <= 0x7FF)
	{
		src = ft_strnew(3);
		src[0] = (w >> 6) + 0xC0;
		src[1] = (w & 0x3F) + 0x80;
		src[2] = '\0';
	}
	else
		src = ws_bis(w);
	return (src);
}

size_t	wstrlen(wchar_t *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] <= 0x70F)
			i++;
		else if (str[j] <= 0x7FF)
			i += 2;
		else if (str[j] <= 0xFFFF)
			i += 3;
		else if (str[j] <= 0x10FFFF)
			i += 4;
		j++;
	}
	return (i);
}

char	*ws_arg(va_list ap, char c, t_options *opt)
{
	char	*src;
	char	*str;
	wchar_t	*wstr;
	int		i;

	(void)c;
	i = 0;
	wstr = va_arg(ap, wchar_t*);
	opt->wbuff = wstr;
	if (opt->precision == 0)
		return ("");
	if (wstr == NULL)
		src = "(null)";
	else
	{
		src = ft_strnew(wstrlen(wstr) + 1);
		opt->free2 = 1;
		while (wstr[i])
		{
			str = ft_wputchar(wstr[i++]);
			src = ft_strcat(src, str);
			free(str);
		}
	}
	return (src);
}
