/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:31:41 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/17 19:52:34 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;
	size_t			i;

	t = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		t[i] = 0;
		i++;
	}
}
