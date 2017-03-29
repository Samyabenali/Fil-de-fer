/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:07:08 by sait-ben          #+#    #+#             */
/*   Updated: 2017/03/29 15:43:11 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_struc(t_param *struc)
{
	struc->r = 255;
	struc->g = 255;
	struc->b = 255;
	struc->dim = 1000;
	struc->off_x = 0;
	struc->off_y = 0;
	struc->min = 0;
	struc->max = 0;
	struc->line = -1;
	struc->col = -1;
}

int		main(int argc, char **argv)
{
	t_param	struc;
	int		ret;

	if (argc != 2)
		return (0);
	if (argc == 2)
	{
		init_struc(&struc);
		ret = my_open(argv[1], &struc);
		if (ret == -1)
			return (0);
		struc.zoom = 5;
		struc.mlx = mlx_init();
		struc.win = mlx_new_window(struc.mlx, struc.dim, struc.dim, "mlx 42");
		print_img(struc);
		mlx_key_hook(struc.win, my_key_func, &struc);
		mlx_loop(struc.mlx);
	}
	free(struc.tab);
	return (0);
}
