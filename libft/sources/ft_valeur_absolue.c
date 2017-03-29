/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valeur_absolue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:29:16 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/17 12:30:06 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

uintmax_t	ft_valeurabsolue(intmax_t nb)
{
	if (nb >= 0)
		return ((uintmax_t)nb);
	nb = -nb;
	return ((uintmax_t)nb);
}
