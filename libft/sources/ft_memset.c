/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:09:12 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/17 19:53:22 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*t;
	size_t			i;

	i = 0;
	t = (unsigned char*)s;
	while (i < n)
	{
		t[i] = c;
		i++;
	}
	return (s);
}
