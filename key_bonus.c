/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:02:03 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/12 18:51:16 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	projection(int a)
{
	if (a == 1)
		return (0);
	return (1);
}

void	depth(int key, t_data *data)
{
	if (key == 0)
		data->depth += 2;
	if (key == 1)
		data->depth -= 2;
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	exit(0);
}

int	press(int key, t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (key == 53)
		free_map(data);
	if (key == 69)
		data->zoom += 2;
	if (key == 78)
		data->zoom -= 2;
	if (key == 124)
		data->shift_x += 20;
	if (key == 123)
		data->shift_x -= 20;
	if (key == 125)
		data->shift_y += 20;
	if (key == 126)
		data->shift_y -= 20;
	if (key == 4)
		data->anglex += 0.2;
	if (key == 9)
		data->angley += 0.2;
	depth(key, data);
	if (key == 35)
		data->p = projection(data->p);
	draw(data);
	return (0);
}	

int	mouseh(int button, int x, int y, t_data *data)
{
	data->color = 0;
	mlx_clear_window(data->mlx, data->win);
	if (button == 5)
		data->zoom += 2;
	if (button == 4)
		data->zoom -= 2;
	if (button == 1)
	{
		data->shift_x = x;
		data->shift_y = y;
	}
	draw(data);
	return (0);
}
