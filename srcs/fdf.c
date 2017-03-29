/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:04:59 by sait-ben          #+#    #+#             */
/*   Updated: 2017/03/29 11:49:26 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel(t_param *struc, t_bresen bresen)
{
	if (bresen.x >= 0 && bresen.y >= 0 && bresen.x
			< struc->dim && bresen.y < struc->dim)
	{
		struc->pixel_img = mlx_get_data_addr(struc->nimg,
				&(struc->bpp), &(struc->s_line), &(struc->ed));
		struc->pixel_img[bresen.x * struc->bpp / 8 +
			bresen.y * struc->s_line] = (unsigned char)struc->b;
		struc->pixel_img[bresen.x * struc->bpp / 8 +
			1 + bresen.y * struc->s_line] = (unsigned char)struc->g;
		struc->pixel_img[bresen.x * struc->bpp / 8 +
			2 + bresen.y * struc->s_line] = (unsigned char)struc->r;
	}
}

void	horiz(t_bresen bresen, t_param struc)
{
	int	i;

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
		if (struc.min != struc.max && struc.zf != struc.zi && struc.dy != 0)
		{
			i = struc.zi + (bresen.i / (float)struc.dy) * (struc.zf - struc.zi);
			struc.r = roundf(((i - struc.min) /
						(float)(struc.max - struc.min)) * 255);
		}
		draw_pixel(&struc, bresen);
		bresen.i++;
	}
}

void	vertic(t_bresen bresen, t_param struc)
{
	int		i;

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
		if (struc.min != struc.max && struc.zf != struc.zi && struc.dy != 0)
		{
			i = struc.zi + (bresen.i / (float)struc.dy) * (struc.zf - struc.zi);
			struc.g = roundf(((i - struc.min) /
						(float)(struc.max - struc.min)) * 255);
		}
		draw_pixel(&struc, bresen);
		bresen.i++;
	}
}

void	bresenham(t_param struc)
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
	draw_pixel(&struc, bresen);
	if (struc.dx > struc.dy)
		horiz(bresen, struc);
	else
		vertic(bresen, struc);
}

int		my_key_func(int keycode, t_param *struc)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69 && struc->zoom < 25)
		struc->zoom += 2;
	if (keycode == 78 && struc->zoom >= 5)
		struc->zoom -= 2;
	if (keycode == 123)
		struc->off_x -= 5;
	if (keycode == 124)
		struc->off_x += 5;
	if (keycode == 125)
		struc->off_y -= 5;
	if (keycode == 126)
		struc->off_y += 5;
	print_img(*struc);
	return (0);
}
