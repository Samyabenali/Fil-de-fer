/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:04:59 by sait-ben          #+#    #+#             */
/*   Updated: 2016/12/28 14:24:50 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>

void        draw_pixel(t_param *struc, int x, int y, t_color color)
{
	struc->pixel_img = mlx_get_data_addr(struc->nimg, &(struc->bpp), &(struc->s_line), &(struc->ed));
	struc->pixel_img[x * struc->bpp / 8 + y * struc->s_line] = (unsigned char)color.b;
	struc->pixel_img[x * struc->bpp / 8 + 1 + y * struc->s_line] = (unsigned char)color.g;
	struc->pixel_img[x * struc->bpp / 8 + 2 + y * struc->s_line] = (unsigned char)color.r;
}

void	bresenham2(t_param struc)
{
	int x;
	int y;
	int xinc;
	int yinc;
	int e;
	int i;
	t_color	color;

	x = struc.xi;
	y = struc.yi;
	struc.dx = struc.xf - struc.xi;
	struc.dy = struc.yf - struc.yi;
	xinc = (struc.dx > 0) ? 1 : -1;
	yinc = (struc.dy > 0) ? 1 : -1;
	struc.dx = abs(struc.dx);
	struc.dy = abs(struc.dy);
	color.r = 255;
	color.g = 255;
	color.b = 255;
	draw_pixel(&struc, x, y, color);
	if (struc.dx > struc.dy)
	{
		e = struc.dx / 2;
		i = 1;
		while (i <= struc.dx)
		{
			x += xinc;
			e += struc.dy;
			if (e >= struc.dx)
			{
				e -= struc.dx;
				y += yinc;
			}
			draw_pixel(&struc, x, y, color);
			i++;
		}
	}
	else
	{
		e = struc.dy / 2;
		i = 1;
		while (i <= struc.dy)
		{	
			y += yinc;
			e += struc.dx;
			if (e >= struc.dy)
			{
				e -= struc.dy;
				x += xinc;
			}
			draw_pixel(&struc, x, y, color);
			i++;
		}
	}
}

int		my_key_func(int keycode, t_param *struc)
{
	printf("key_event %d\n", keycode);
	return (0);
}

int		main()
{
	t_param	struc;

	struc.mlx = mlx_init();
	struc.win = mlx_new_window(struc.mlx, 400, 400, "mlx 42");
	struc.nimg = mlx_new_image(struc.mlx, 400, 400);
	struc.yi = 50;
	struc.xi = 50;
	struc.xf = 100;
	struc.yf = 0;
	bresenham2(struc);	
	struc.yi = 0;
	struc.xi = 100;
	struc.xf = 150;
	struc.yf = 50;
	bresenham2(struc);	
	struc.yi = 50;
	struc.xi = 50;
	struc.xf = 100;
	struc.yf = 100;
	bresenham2(struc);	
	struc.yi = 100;
	struc.xi = 100;
	struc.xf = 150;
	struc.yf = 50;
	bresenham2(struc);
	struc.retimg = mlx_put_image_to_window(struc.mlx, struc.win, struc.nimg, 0, 0);
	mlx_key_hook(struc.win, my_key_func, &struc);
	mlx_loop(struc.mlx);
	return (0);
}

