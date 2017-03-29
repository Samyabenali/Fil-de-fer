/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:41:19 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/22 12:41:28 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_wcount(char *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			word++;
		}
		i++;
	}
	return (word);
}

static size_t	ft_len_word(char *s, int start, char c)
{
	size_t len;

	len = 0;
	while (s[start] == c && s[start])
		start++;
	while (s[start] != c && s[start])
	{
		start++;
		len++;
	}
	return (len);
}

static char		**ft_split(char const *s, char c, int wcount)
{
	size_t	i;
	size_t	j;
	char	**str;

	if ((str = (char**)malloc(sizeof(char*) * wcount + 1)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			str[j] = ft_strsub(s, i, ft_len_word((char*)s, i, c));
			i = i + ft_len_word((char*)s, i, c);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		wcount;

	if (c && s)
		wcount = ft_wcount((char*)s, c);
	if (s)
	{
		str = ft_split((char*)s, c, wcount);
		return (str);
	}
	return (NULL);
}
