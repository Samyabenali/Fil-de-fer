/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 10:55:14 by sait-ben          #+#    #+#             */
/*   Updated: 2016/12/28 16:44:47 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

# define BUFF_SIZE2 32000

int		int_count(char **str)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		*convert_int(char **str)
{
	int		*tab;
	int		i;

	i = 0;
	if ((tab = (int*)malloc(sizeof(int) * (int_count(str) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	tab[i] = 9999;
	return (tab);
}

int		line_count(int fd)
{
	char buff[BUFF_SIZE2 + 1];
	int count;
	int ret;
	int i;
	
	ret = read(fd, buff, BUFF_SIZE2);
	buff[ret] = '\0';
	count = 0;
	i = 0;
	while (buff[i] != '\0')
	{	
		if (buff[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int		**split(int fd, int nb_line, t_var *struc2)
{
	char 	**tab;
	char 	*line;
	int 	j;
	
	struc2->tab = (int**)malloc(sizeof(int*) * (nb_line + 1));
	j = 0;
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		struc2->tab[j] = convert_int(tab);
		j++;
	}
	return (struc2->tab);
}


int		my_open(char *argv, t_var *struc2)
{
	int fd;
		
	fd = open(argv, O_RDONLY);
	struc2->nb_line = line_count(fd);
	close(fd);
	fd = open(argv, O_RDONLY);
	struc2->tab = split(fd, struc2->nb_line, struc2);
	close(fd);
	return (0);
}
