/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:35:54 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/10 15:35:58 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		largeur(char *str, int i, t_options *opt)
{
	opt->largeur = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		opt->largeur = (opt->largeur) * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}

int		precision(char *str, int i, t_options *opt)
{
	opt->precision = 0;
	i++;
	while (str[i] <= 57 && str[i] >= 48)
	{
		opt->precision = opt->precision * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}
