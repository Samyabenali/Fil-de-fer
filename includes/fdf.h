/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:54:09 by sait-ben          #+#    #+#             */
/*   Updated: 2017/03/29 12:34:23 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/sources/libft.h"
# include <math.h>
# include "mlx.h"

typedef struct	s_param
{
	int			xi;
	int			yi;
	int			xf;
	int			yf;
	int			dx;
	int			dy;
	void		*mlx;
	void		*win;
	void		*nimg;
	int			retimg;
	char		*pixel_img;
	int			bpp;
	int			ed;
	int			s_line;
	int			dim;
	int			**tab;
	char		line;
	char		col;
	int			zoom;
	int			r;
	int			g;
	int			b;
	int			off_x;
	int			off_y;
	int			max;
	int			min;
	int			zi;
	int			zf;
}				t_param;

typedef struct	s_bresen
{
	int			x;
	int			y;
	int			xinc;
	int			yinc;
	int			e;
	int			i;
}				t_bresen;

int				my_open(char *argv, t_param *struc);
void			bresenham(t_param struc);
int				my_key_func(int keycode, t_param *struc);
void			proj_vert(t_param struc);
void			proj_horiz(t_param struc);
void			print_img(t_param struc);

#endif
