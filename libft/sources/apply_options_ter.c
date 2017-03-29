/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options_ter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:14:04 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/23 16:32:20 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_hashtag2(char *res, t_options *opt)
{
	char	*str;
	int		i;
	int		j;

	j = -1;
	i = 0;
	str = ft_strnew(ft_strlen(res) + 2);
	opt->free2 = 1;
	while (res[j++] == ' ')
		str[i++] = ' ';
	i--;
	if (res[j] == '0')
		return (res);
	str[i] = '0';
	i++;
	while (res[j])
		str[i++] = res[j++];
	str[i] = '\0';
	free(res);
	return (str);
}

char	*apply_space_2(char *str, int i, t_options *opt)
{
	int		len;
	char	*src;

	len = ft_strlen(str) + 2;
	if (opt->space == 1 && opt->zero == 1 && ft_atoi(str) == 0)
		len--;
	src = ft_strnew(len);
	opt->free2 = 1;
	src[i] = ' ';
	src[len - 1] = '\0';
	i++;
	while (i < len - 1)
	{
		src[i] = str[i - 1];
		i++;
	}
	free(str);
	return (src);
}
