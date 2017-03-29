/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:46:36 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/19 17:11:16 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(const char *s, const char *t)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (t[0] == '\0')
		return ((char*)s);
	while (s[i])
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
