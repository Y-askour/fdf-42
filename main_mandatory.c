/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:15:27 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/15 18:21:23 by yaskour          ###   ########.fr       */
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
	data.shift_x = WIN_WIDTH / 2;
	data.shift_y = WIN_HEIGHT / 2 - 500;
	data.p = 1;
	data.anglex = 0.523599;
	data.angley = 0.523599;
	data.depth = 1;
	read_fdf(argv[1], &data);
	if (data.height < 100 && data.width < 100)
		data.zoom = 10;
	else
		data.zoom = 3;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	draw(&data);
	mlx_key_hook(data.win, press, &data);
	mlx_loop(data.mlx);
}
