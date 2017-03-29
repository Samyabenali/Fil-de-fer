/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:34:16 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/19 12:45:58 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dest2;

	src1 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dest2[i] = src1[i];
		if (dest2[i] == (unsigned char)c)
			return (dest2 + i + 1);
		i++;
	}
	return (NULL);
}
