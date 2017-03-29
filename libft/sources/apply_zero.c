/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:30:49 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/23 16:09:43 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_zero_x(char *res, t_options *opt)
{
	int		i;

	i = 0;
	res[0] = '0';
	res[1] = opt->type;
	i = 2;
	while (res[i] != opt->type)
		res[i++] = '0';
	res[i] = '0';
	return (res);
}

char	*apply_zero_p(char *res, t_options *opt)
{
	int		i;
	char	*src;

	i = 0;
	src = ft_strdup(res);
	opt->free2 = 1;
	src[0] = '0';
	src[1] = 'x';
	i = 2;
	while (src[i] != 'x' && src[i])
		src[i++] = '0';
	src[i] = '0';
	free(res);
	return (src);
}

char	*apply_zero_2(char *res, t_options *opt)
{
	int		i;

	i = 0;
	if ((opt->type == 'x' || opt->type == 'X') && opt->hashtag == 1)
		return (apply_zero_x(res, opt));
	if (opt->type == 'p' && (opt->zero == 1 && checkzerox(res) == 1))
		return (apply_zero_p(res, opt));
	else
	{
		i = 0;
		while (res[i])
		{
			if (res[i] == ' ')
				res[i] = '0';
			i++;
		}
	}
	return (res);
}

char	*apply_zero_3(char *res, t_options *opt, char *src)
{
	int		i;
	int		j;

	src = ft_strnew(ft_strlen(res) + 1);
	opt->free2 = 1;
	src[0] = '-';
	i = 1;
	j = 0;
	while (res[j])
	{
		while (res[j] == ' ')
		{
			src[i++] = '0';
			j++;
		}
		if (res[j] == '-')
		{
			src[i] = '0';
			j++;
		}
		src[i++] = res[j++];
	}
	src[i] = '\0';
	free(res);
	return (src);
}

char	*apply_zero(char *res, t_options *opt)
{
	char	*src;

	src = NULL;
	if (opt->moins == 1)
		return (res);
	if (ft_atoi_max(res) < 0)
		return (apply_zero_3(res, opt, src));
	else
		return (apply_zero_2(res, opt));
}
