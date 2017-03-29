/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:07:22 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/23 15:29:16 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*oh_arg(va_list ap, uintmax_t nb, t_options *opt)
{
	int			i;
	int			j;
	char		*str;
	char		*res;

	(void)opt;
	(void)ap;
	i = 0;
	j = 0;
	res = ft_itoa_base_uint(nb, 8);
	str = ft_strnew(ft_strlen(res + 2));
	opt->free1 = 1;
	str[0] = '0';
	i++;
	while (res[j])
		str[i++] = res[j++];
	str[i] = '\0';
	free(res);
	opt->free1 = 1;
	return (str);
}

char	*o_arg(va_list ap, char c, t_options *opt)
{
	int			i;
	int			j;
	uintmax_t	k;
	char		*str;
	char		*res;

	k = va_arg(ap, unsigned int);
	if (c == 'o' && opt->hashtag == 1 && k != 0)
	{
		i = 0;
		j = 0;
		res = ft_itoa_base(k, 8);
		str = ft_strnew(ft_strlen(res + 2));
		opt->free1 = 1;
		str[0] = '0';
		i++;
		while (res[j])
			str[i++] = res[j++];
		str[i] = '\0';
		free(res);
		return (str);
	}
	else
		return (ft_itoa_base_uint(ft_valeurabsolue(k), 8));
}

char	*int_arg_2(va_list ap, char c, t_options *opt)
{
	char	*str;

	opt->free1 = 1;
	if (c == 'o' && opt->taille == 0)
	{
		str = o_arg(ap, c, opt);
		return (str);
	}
	if (c == 'x')
	{
		str = ft_itoa_base((va_arg(ap, unsigned int)), 16);
		return (str);
	}
	if (c == 'X')
	{
		str = ft_maj(ft_itoa_base((va_arg(ap, unsigned int)), 16));
		return (str);
	}
	if (c == 'u' && opt->taille == 0)
		return (ft_itoa_base(va_arg(ap, unsigned int), 10));
	else
		str = ft_itoa_base(va_arg(ap, int), 10);
	return (str);
}

char	*int_arg3(va_list ap, uintmax_t nb, char c, t_options *opt)
{
	opt->free1 = 1;
	nb = unsigned_cast(ap, opt);
	if (c == 'o' && opt->hashtag == 0)
		return (ft_itoa_base_uint(nb, 8));
	if (c == 'o' && opt->hashtag == 1)
		return (oh_arg(ap, nb, opt));
	if (c == 'u')
		return (ft_itoa_base_uint(nb, 10));
	if (c == 'X')
		return (ft_maj(ft_itoa_base_uint(nb, 16)));
	return (ft_itoa_base_uint(nb, 16));
}

char	*int_arg(va_list ap, char c, t_options *opt)
{
	uintmax_t	nb;
	intmax_t	nbb;

	nb = 0;
	if (opt->taille != 0 && ft_strchr("di", c) != NULL)
	{
		nbb = signed_cast(ap, opt);
		if (nbb == -9223372036854775807 - 1)
			return ("-9223372036854775808");
		opt->free1 = 1;
		return (ft_itoa_base(nbb, 10));
	}
	if (opt->taille != 0 && ft_strchr("ouxX", c) != NULL)
		return (int_arg3(ap, nb, c, opt));
	else
		return (int_arg_2(ap, c, opt));
}
