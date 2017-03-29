/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:07:18 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/23 16:35:20 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_precision_neg(char *str, t_options *opt)
{
	int		i;
	int		j;
	char	*src;

	src = ft_strnew(opt->precision + 2);
	opt->free2 = 1;
	i = 1;
	j = 1;
	src[0] = '-';
	src[opt->precision + 1] = '\0';
	while (str[j])
	{
		while (i <= (opt->precision - (int)ft_strlen(str) + 1))
		{
			src[i] = '0';
			i++;
		}
		while (str[j])
			src[i++] = str[j++];
		opt->zero = 0;
	}
	src[i] = '\0';
	free(str);
	return (src);
}

char	*apply_precision_2(char *str, t_options *opt)
{
	char	*src;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	if (ft_atoi(str) < 0)
		return (apply_precision_neg(str, opt));
	src = ft_strnew(opt->precision + 1);
	opt->free2 = 1;
	while ((i < (opt->precision - (int)ft_strlen(str))) && opt->type != 's')
	{
		src[i] = '0';
		i++;
	}
	src[opt->precision] = '\0';
	while (str[j])
		src[i++] = str[j++];
	src[i] = '\0';
	opt->zero = 0;
	if (opt->type != 's')
		free(str);
	return (src);
}

char	*apply_precision(char *str, char c, t_options *opt)
{
	int		len;

	len = (int)ft_strlen(str);
	if (opt->precision == 0 && ft_atoi(str) == 0 &&
			opt->type != '%' && c != 'p')
	{
		str = ft_strnew(1);
		str[0] = '\0';
		return (str);
	}
	if (len >= opt->precision && c == 's')
	{
		opt->free2 = 1;
		return (ft_strsub(str, 0, opt->precision));
	}
	if (len >= opt->precision && c == 'S')
		return (ft_strsubwchar(str, 0, opt));
	if ((int)ft_strlen(str) >= opt->precision)
		return (str);
	if (len < opt->precision && (opt->type == 'c' || opt->type == 'C'))
		return (str);
	if (opt->precision != -1 && opt->type == '%')
		return (str);
	else
		return (apply_precision_2(str, opt));
}
