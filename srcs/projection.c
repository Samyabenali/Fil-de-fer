/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:26:35 by sait-ben          #+#    #+#             */
/*   Updated: 2017/03/29 11:50:06 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	proj_horiz(t_param struc)
{
	int	i;
	int	j;

	j = 0;
	while (j < struc.line)
	{
		i = 0;
		while (i < struc.col - 1)
		{
			struc.xi = (struc.dim / 2) - (j - i) * struc.zoom;
			struc.yi = (j + i) * struc.zoom -
				struc.tab[j][i] * (struc.zoom / 6);
			struc.xf = (struc.dim / 2) -
				(j - (i + 1)) * struc.zoom;
			struc.yf = (j + i + 1) * struc.zoom -
				struc.tab[j][i + 1] * (struc.zoom / 6);
			struc.zi = struc.tab[j][i];
			struc.zf = struc.tab[j][i + 1];
			bresenham(struc);
			i++;
		}
		j++;
	}
}

void	proj_vert(t_param struc)
{
	int	i;
	int	j;

	j = 0;
	while (j < struc.line - 1)
	{
		i = 0;
		while (i < struc.col)
		{
			struc.xi = (struc.dim / 2) - (j - i) * struc.zoom;
			struc.yi = (j + i) * struc.zoom -
				struc.tab[j][i] * (struc.zoom / 6);
			struc.xf = (struc.dim / 2) - (j + 1 - i) * struc.zoom;
			struc.yf = (j + 1 + i) * struc.zoom -
				struc.tab[j + 1][i] * (struc.zoom / 6);
			struc.zi = struc.tab[j][i];
			struc.zf = struc.tab[j + 1][i];
			bresenham(struc);
			i++;
		}
		j++;
	}
}

void	print_img(t_param struc)
{
	mlx_clear_window(struc.mlx, struc.win);
	struc.nimg = mlx_new_image(struc.mlx, struc.dim, struc.dim);
	proj_horiz(struc);
	proj_vert(struc);
	struc.retimg = mlx_put_image_to_window(struc.mlx, struc.win, struc.nimg,
			struc.off_x, struc.off_y);
}
