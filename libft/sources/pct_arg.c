/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:50:21 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/22 13:29:58 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*pct_arg(va_list ap, char c, t_options *opt)
{
	char	*res;

	(void)opt;
	(void)ap;
	if (c == '%')
	{
		res = ft_strnew(2);
		res[0] = '%';
		res[1] = '\0';
		opt->free1 = 1;
	}
	if (c == 'Z')
	{
		res = ft_strnew(2);
		res[0] = 'Z';
		res[1] = '\0';
	}
	if (c == 'R')
	{
		res = ft_strnew(2);
		res[0] = 'R';
		res[1] = '\0';
	}
	return (res);
}
