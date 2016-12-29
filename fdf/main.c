/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:07:08 by sait-ben          #+#    #+#             */
/*   Updated: 2016/12/28 18:16:46 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int 		ret;
	t_var	struc2;
	int		i;
	t_param	struc;
	t_color	color;
	int 	j;

	if (argc != 2)
		return (0);
	if (argc == 2)
	{
		i = 0;
		j = 0;
		color.r = 255;
		color.g = 255;
		color.b = 255;
		ret = my_open(argv[1], &struc2);
		struc.mlx = mlx_init();
		struc.win = mlx_new_window(struc.mlx, 600, 600, "mlx 42");
		struc.nimg = mlx_new_image(struc.mlx, 600, 600);
		i = 0;
		while (i < struc2.nb_line)
		{
			j = 0;
			while (struc2.tab[i][j] != 9999)
			{
				struc.xi = i * 20;
				struc.yi = j * 20;
				struc.xf = (i + 1) * 20;
				struc.yf = j * 20;
				bresenham(struc, color);
				j++;
			}
			i++;
		}
		j = 0;
		while (j < struc2.nb_line)
		{
			i = 0;
			while (struc2.tab[j][i] != 9999)
			{
				struc.xi = j * 20;
				struc.yi = i * 20;
				struc.xf = (j + 1) * 20;
				struc.yf = i * 20;
				bresenham(struc, color);
				i++;
			}
			j++;
		}
		struc.retimg = mlx_put_image_to_window(struc.mlx, struc.win, struc.nimg, 0, 0);
		mlx_key_hook(struc.win, my_key_func, &struc);
		mlx_loop(struc.mlx);
	}
	return (0);
}
