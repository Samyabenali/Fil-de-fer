/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:12:31 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/23 15:12:14 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		in_out2(char *src, t_options *opt)
{
	int		len;

	len = 0;
	ft_putstr(src);
	len = ft_strlen(src);
	if (opt->free2 == 1 && opt->free1 == 0)
	{
		opt->free2 = 0;
		free(src);
		src = NULL;
	}
	if (opt->free2 == 1 && opt->free1 == 1)
	{
		opt->free2 = 0;
		free(src);
		src = NULL;
	}
	if ((opt->type == 'c' && len == 0) || opt->slen == 1)
	{
		ft_putchar('\0');
		init_flags(opt);
		return (len + 1);
	}
	return (len);
}

int		in_out(va_list ap, char c, t_options *opt)
{
	char	*str;
	char	*src;
	int		len;

	opt->type = c;
	str = parsing(ap, c, opt);
	if (c == 'p' && opt->precision >= (int)ft_strlen(str))
		src = apply_precision_p(str, opt);
	else
	{
		src = apply_options(str, c, opt);
		if (opt->free1 == 1 && opt->free2 == 0)
		{
			opt->free1 = 0;
			free(str);
			str = NULL;
		}
	}
	if (opt->type == 'Z' && opt->precision != -1)
		src = apply_z(src);
	len = in_out2(src, opt);
	init_flags(opt);
	return (len);
}
