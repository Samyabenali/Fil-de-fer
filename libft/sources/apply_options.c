/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:58:10 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/23 16:33:28 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_largeur(char *str, t_options *opt)
{
	char	*src;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((int)ft_strlen(str) >= opt->largeur)
		return (str);
	if (opt->largeur != 0 && opt->type == 'c' && *str == 0)
		opt->slen = 1;
	src = ft_strnew(opt->largeur + 1);
	while (i < (opt->largeur - (int)ft_strlen(str) - opt->slen))
	{
		src[i] = ' ';
		i++;
	}
	while (j < (int)ft_strlen(str))
		src[i++] = str[j++];
	src[i] = '\0';
	if (opt->free2 == 1 || opt->free1 == 1)
		free(str);
	opt->free2 = 1;
	return (src);
}

char	*apply_plus_2(char *str, t_options *opt)
{
	char	*src;
	int		i;

	i = 0;
	src = ft_strnew(ft_strlen(str) + 2);
	opt->free2 = 1;
	src[i] = '+';
	i++;
	src[ft_strlen(str) + 1] = '\0';
	while (i <= (int)ft_strlen(str))
	{
		src[i] = str[i - 1];
		i++;
	}
	free(str);
	return (src);
}

char	*apply_plus(char *str, char c, t_options *opt)
{
	int		i;

	(void)opt;
	i = 0;
	if (ft_atoi(str) < 0 || ft_strchr("di", c) == NULL)
		return (str);
	if (opt->zero != 0 && str[0] == '0')
	{
		str[0] = '+';
		return (str);
	}
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
		i--;
		str[i] = '+';
		return (str);
	}
	else
		return (apply_plus_2(str, opt));
}

char	*apply_space(char *str, char c, t_options *opt)
{
	int		i;

	i = 0;
	if (ft_atoi(str) < 0 || opt->plus == 1 || str[i] == ' '
			|| ft_strchr("di", c) == NULL)
		return (str);
	else
		return (apply_space_2(str, i, opt));
}

char	*apply_options(char *str, char c, t_options *opt)
{
	if (opt->precision == 0 && opt->hashtag == 1 && (c == 'o'
				|| c == 'O') && ft_atoi(str) == 0)
		return ("0");
	if (opt->precision != -1)
		str = apply_precision(str, c, opt);
	if (opt->hashtag != 0 && (c == 'x' || c == 'X'))
		str = apply_hashtag_x(str, opt);
	if (opt->largeur != -1)
		str = apply_largeur(str, opt);
	if (opt->zero != 0)
		str = apply_zero(str, opt);
	if (opt->space != 0)
		str = apply_space(str, c, opt);
	if (opt->plus != 0)
		str = apply_plus(str, c, opt);
	if (opt->hashtag != 0 && c != 'x' && c != 'X')
		str = apply_hashtag(str, opt);
	if (opt->moins != 0)
		str = apply_moins(str, opt);
	return (str);
}
