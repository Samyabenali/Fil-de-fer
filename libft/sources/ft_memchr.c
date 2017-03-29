/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:40:38 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/17 20:13:19 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	unsigned char	d;
	size_t			i;

	t = (unsigned char*)s;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (t[i] == d)
			return (t + i);
		i++;
	}
	return (NULL);
}
