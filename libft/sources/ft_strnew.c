/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:34:18 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/20 12:22:12 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = (char*)malloc(sizeof(char) * size + 1);
	if (newstr == NULL)
		return (NULL);
	while (i < size + 1)
	{
		newstr[i] = '\0';
		i++;
	}
	return (newstr);
}
