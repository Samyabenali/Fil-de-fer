/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:54:09 by sait-ben          #+#    #+#             */
/*   Updated: 2016/12/28 16:51:36 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct	s_param
{
	int 		xi;
	int 		yi;
	int			xf;
	int			yf;
	int 		dx;
	int 		dy;
	void		*mlx;
	void		*win;
	void		*nimg;
	int			retimg;
	char		*pixel_img;
	int			bpp;
	int			ed;
	int			s_line;

}				t_param;

typedef struct s_bresen
{
	int			x;
	int			y;
	int			xinc;
	int			yinc;
	int			e;
	int			i;
}				t_bresen;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;


typedef struct	s_var
{
	int			**tab;
	char		nb_line;
}				t_var;

int				my_open(char *argv, t_var *struc2);
void			bresenham(t_param struc, t_color color);
int				my_key_func(int keycode, t_param *struc);

# endif

