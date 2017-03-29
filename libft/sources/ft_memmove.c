/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:53:17 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/21 14:28:09 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)src;
	str2 = (unsigned char*)dest;
	if (src < dest)
	{
		while (n > 0)
		{
			str2[n - 1] = str1[n - 1];
			n--;
		}
	}
	if (src > dest)
		str2 = ft_memcpy(str2, str1, n);
	return (str2);
}
