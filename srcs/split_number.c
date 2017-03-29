/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 10:55:14 by sait-ben          #+#    #+#             */
/*   Updated: 2017/03/29 15:41:36 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define BUFF_SIZE2 32000

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

int		*convert_int(char **str, t_param *struc)
{
	int		*tab;
	int		i;

	i = 0;
	if ((tab = (int*)malloc(sizeof(int) * (int_count(str) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		tab[i] = ft_atoi(str[i]);
		if (tab[i] == -999999 || tab[i] == ' ')
		{
			ft_printf("Error\n");
			return (NULL);
		}
		if (tab[i] < struc->min)
			struc->min = tab[i];
		if (tab[i] > struc->max)
			struc->max = tab[i];
		i++;
	}
	tab[i] = 9999;
	if (i != struc->col && struc->col != -1)
		return (NULL);
	struc->col = i;
	return (tab);
}

void	line_count(int fd, t_param *struc)
{
	char	buff[BUFF_SIZE2 + 1];
	int		count;
	int		ret;
	int		i;

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
	struc->line = count;
}

int		split(int fd, t_param *struc)
{
	char	**tab;
	char	*line;
	int		j;
	int		err;

	struc->tab = (int**)malloc(sizeof(int*) * (struc->line + 1));
	j = 0;
	err = 0;
	while (get_next_line(fd, &line))
	{
		if ((tab = ft_strsplit(line, ' ')) == NULL)
			return (-1);
		struc->tab[j] = convert_int(tab, struc);
		if (struc->tab[j] == NULL)
			return (-1);
		j++;
		free(line);
	}
	return (0);
}

int		my_open(char *argv, t_param *struc)
{
	int fd;
	int	i;

	fd = open(argv, O_RDONLY);
	line_count(fd, struc);
	close(fd);
	fd = open(argv, O_RDONLY);
	i = split(fd, struc);
	if (i == -1)
		return (-1);
	close(fd);
	return (0);
}
