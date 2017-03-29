/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_detect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 09:50:21 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/15 16:55:53 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		taille2(char *str, int i, t_options *opt)
{
	if (str[i] == 'j')
	{
		opt->taille = 5;
		i++;
	}
	if (str[i] == 'z')
	{
		opt->taille = 6;
		i++;
	}
	return (i);
}

int		taille(char *str, int i, t_options *opt)
{
	if (str[i] == 'h')
	{
		opt->taille = 1;
		i++;
		if (str[i] == 'h')
		{
			opt->taille = 2;
			i++;
		}
	}
	if (str[i] == 'l')
	{
		opt->taille = 3;
		i++;
		if (str[i] == 'l')
		{
			opt->taille = 4;
			i++;
		}
	}
	i = taille2(str, i, opt);
	return (i);
}

int		detect2(char *str, int i, t_options *opt)
{
	if (str[i] > 48 && str[i] <= 57)
		i = largeur(str, i, opt);
	if (str[i] == '.')
		i = precision(str, i, opt);
	while (str[i] == '#')
	{
		opt->hashtag = 1;
		i++;
	}
	if (ft_strchr("hljz", str[i]) != NULL)
		i = taille(str, i, opt);
	return (i);
}

int		option_detect(char *str, int i, t_options *opt)
{
	while (str[i] == '-')
	{
		opt->moins = 1;
		i++;
	}
	while (str[i] == '+')
	{
		opt->plus = 1;
		i++;
	}
	while (str[i] == '0')
	{
		opt->zero = 1;
		i++;
	}
	while (str[i] == ' ')
	{
		opt->space = 1;
		i++;
	}
	i = detect2(str, i, opt);
	return (i);
}
