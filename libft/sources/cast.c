/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:32:20 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/18 14:33:58 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

intmax_t	signed_cast(va_list ap, t_options *opt)
{
	intmax_t nb;

	if (opt->taille == 2)
		nb = (char)va_arg(ap, int);
	if (opt->taille == 1)
		nb = (short)va_arg(ap, int);
	if (opt->taille == 3)
		nb = va_arg(ap, long int);
	if (opt->taille == 4)
		nb = va_arg(ap, long long int);
	if (opt->taille == 5)
		nb = va_arg(ap, intmax_t);
	if (opt->taille == 6)
		nb = va_arg(ap, size_t);
	return (nb);
}

uintmax_t	unsigned_cast(va_list ap, t_options *opt)
{
	uintmax_t nb;

	if (opt->taille == 2)
		nb = (unsigned char)va_arg(ap, unsigned int);
	if (opt->taille == 1)
		nb = (unsigned short)va_arg(ap, unsigned int);
	if (opt->taille == 3)
		nb = va_arg(ap, unsigned long int);
	if (opt->taille == 4)
		nb = va_arg(ap, unsigned long long int);
	if (opt->taille == 5)
		nb = va_arg(ap, uintmax_t);
	if (opt->taille == 6)
		nb = va_arg(ap, ssize_t);
	return (nb);
}
