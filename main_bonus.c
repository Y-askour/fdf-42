/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:15:27 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/14 18:24:40 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf path/to/map.fdf", 0);
		return (0);
	}
	data.zoom = 20;
	data.shift_x = win_width / 2;
	data.shift_y = win_height / 2;
	data.p = 1;
	data.anglex = 0.523599;
	data.angley = 0.523599;
	data.depth = 1;
	read_fdf(argv[1], &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, win_width, win_height, "fdf");
	draw(&data);
	mlx_key_hook(data.win, press, &data);
	mlx_mouse_hook(data.win, mouseh, &data);
	mlx_loop(data.mlx);
}
