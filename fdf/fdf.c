/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:04:59 by sait-ben          #+#    #+#             */
/*   Updated: 2016/12/28 16:44:33 by sait-ben         ###   ########.fr       */
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

void	horiz(t_bresen bresen, t_param struc, t_color color)
{
		bresen.e = struc.dx / 2;
		bresen.i = 1;
		while (bresen.i <= struc.dx)
		{
			bresen.x += bresen.xinc;
			bresen.e += struc.dy;
			if (bresen.e >= struc.dx)
			{
				bresen.e -= struc.dx;
				bresen.y += bresen.yinc;
			}
			draw_pixel(&struc, bresen.x, bresen.y, color);
			bresen.i++;
		}
}

void	vertic(t_bresen bresen, t_param struc, t_color color)
{
		bresen.e = struc.dy / 2;
		bresen.i = 1;
		while (bresen.i <= struc.dy)
		{	
			bresen.y += bresen.yinc;
			bresen.e += struc.dx;
			if (bresen.e >= struc.dy)
			{
				bresen.e -= struc.dy;
				bresen.x += bresen.xinc;
			}
			draw_pixel(&struc, bresen.x, bresen.y, color);
			bresen.i++;
		}
}

void	bresenham(t_param struc, t_color color)
{
	t_bresen	bresen;

	bresen.x = struc.xi;
	bresen.y = struc.yi;
	struc.dx = struc.xf - struc.xi;
	struc.dy = struc.yf - struc.yi;
	bresen.xinc = (struc.dx > 0) ? 1 : -1;
	bresen.yinc = (struc.dy > 0) ? 1 : -1;
	struc.dx = abs(struc.dx);
	struc.dy = abs(struc.dy);
	color.r = 255;
	color.g = 255;
	color.b = 255;
	draw_pixel(&struc, bresen.x, bresen.y, color);
	if (struc.dx > struc.dy)
		horiz(bresen, struc, color);
	else
		vertic(bresen, struc, color);
}

int		my_key_func(int keycode, t_param *struc)
{
	struc = NULL;
	printf("key_event %d\n", keycode);
	return (0);
}
/*
int		main()
{
	t_param	struc;
	t_color	color;

	struc.mlx = mlx_init();
	struc.win = mlx_new_window(struc.mlx, 400, 400, "mlx 42");
	struc.nimg = mlx_new_image(struc.mlx, 400, 400);
	struc.yi = 50;
	struc.xi = 50;
	struc.xf = 100;
	struc.yf = 0;
	bresenham2(struc, color);	
	struc.yi = 0;
	struc.xi = 100;
	struc.xf = 150;
	struc.yf = 50;
	bresenham2(struc, color);	
	struc.yi = 50;
	struc.xi = 50;
	struc.xf = 100;
	struc.yf = 100;
	bresenham2(struc, color);	
	struc.yi = 100;
	struc.xi = 100;
	struc.xf = 150;
	struc.yf = 50;
	bresenham2(struc, color);
	struc.retimg = mlx_put_image_to_window(struc.mlx, struc.win, struc.nimg, 0, 0);
	mlx_key_hook(struc.win, my_key_func, &struc);
	mlx_loop(struc.mlx);
	return (0);
}
*/
