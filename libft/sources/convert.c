/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:11:02 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/18 13:14:16 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*parsing(va_list ap, char c, t_options *opt)
{
	int								i;
	static const			t_flags g_conv[] = {
		{ "diouxX", &int_arg },
		{ "DOU", &dou_arg },
		{ "Cc", &c_arg },
		{ "s", &s_arg },
		{ "S", &ws_arg },
		{ "p", &p_arg },
		{ "%ZR", &pct_arg }
	};

	i = 0;
	while (i != 7)
	{
		if (ft_strchr(g_conv[i].str, c) != 0)
			return (g_conv[i].f(ap, c, opt));
		i++;
	}
	return (0);
}
