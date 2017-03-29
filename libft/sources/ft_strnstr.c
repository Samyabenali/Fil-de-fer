/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:35:38 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/21 19:38:11 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s, const char *t, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	if (*t == '\0' || t == s)
		return ((char*)s);
	i = 0;
	k = ft_strlen((char*)t);
	while (s[i] && i + k <= len)
	{
		j = 0;
		while (t[j] == s[i + j])
		{
			if (t[j + 1] == '\0')
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
