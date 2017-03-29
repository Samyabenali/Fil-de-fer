/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:31:15 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/18 14:32:35 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		parse_pct(va_list ap, char *str, int i, t_options *opt)
{
	i++;
	if (str[i] == '\0')
		return (i);
	while (ft_strchr(" .0123456789+-#lhzj", str[i]) != NULL && str[i] != '\0')
		i = option_detect(str, i, opt);
	if (str[i] && ft_strchr("diouxXcCDOUsSp%ZR", str[i]) != NULL)
	{
		opt->len += in_out(ap, str[i], opt);
		i++;
	}
	else if (ft_strchr("diouxXcCDOUsSp", str[i]) == NULL)
	{
		ft_putchar(str[i]);
		opt->len++;
		i++;
	}
	return (i);
}

int		ft_printf(char *str, ...)
{
	int			i;
	va_list		ap;
	t_options	opt;

	opt.len = 0;
	i = 0;
	va_start(ap, str);
	init_flags(&opt);
	while (str[i])
	{
		if (str[i] == '%')
			i = parse_pct(ap, str, i, &opt);
		else
		{
			ft_putchar(str[i]);
			i++;
			opt.len++;
		}
	}
	va_end(ap);
	return (opt.len);
}
