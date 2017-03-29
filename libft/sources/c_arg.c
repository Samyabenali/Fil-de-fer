/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:48:07 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/23 11:04:25 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*c_arg_2(va_list ap, wchar_t wt, t_options *opt)
{
	char	*str;

	wt = va_arg(ap, wchar_t);
	if (wt == 0)
		opt->slen = 1;
	str = ft_wputchar(wt);
	opt->free1 = 1;
	return (str);
}

char	*c_arg(va_list ap, char c, t_options *opt)
{
	char	*str;
	char	w;
	wchar_t	wt;

	(void)opt;
	str = NULL;
	if (c == 'c' && opt->taille == 0)
	{
		w = va_arg(ap, int);
		str = ft_strnew(2);
		opt->free1 = 1;
		str[0] = (unsigned char)w;
		str[1] = '\0';
		return (str);
	}
	if (c == 'c' && opt->taille != 0)
	{
		wt = va_arg(ap, wchar_t);
		str = ft_wputchar(wt);
	}
	if (opt->type == 'C')
		return (c_arg_2(ap, wt, opt));
	return (str);
}
