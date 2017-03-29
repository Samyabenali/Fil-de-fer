/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:21:03 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/21 16:45:24 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_flags(t_options *opt)
{
	opt->moins = 0;
	opt->plus = 0;
	opt->hashtag = 0;
	opt->zero = 0;
	opt->space = 0;
	opt->precision = -1;
	opt->largeur = -1;
	opt->taille = 0;
	opt->type = 0;
	opt->slen = 0;
	opt->wbuff = NULL;
	opt->free1 = 0;
	opt->free2 = 0;
}
