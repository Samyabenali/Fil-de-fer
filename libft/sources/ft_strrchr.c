/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:39:49 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/21 13:35:14 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen((char *)s);
	while (i > 0)
	{
		if (s[i] == c)
			return ((char*)s + i);
		i--;
	}
	if (s[0] == c)
		return ((char*)s);
	return (NULL);
}
