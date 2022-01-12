/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:42:00 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/12 18:22:20 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_data *data)
{
	float	a;

	a = *x;
	*x = ((*x - *y)) * cos(data->anglex);
	*y = (a + *y) * sin(data->angley) - z ;
}

void	controler(t_data *data)
{
	int	z;
	int	z1;

	z = data->map[(int)data->y][(int)data->x] * data->depth;
	z1 = data->map[(int)data->y1][(int)data->x1] * data->depth;
	data->x *= data->zoom;
	data->x1 *= data->zoom;
	data->y *= data->zoom;
	data->y1 *= data->zoom;
	if (z != 0)
		data->color = 0x740001;
	else
		data->color = 0xd3a625;
	if (data->p == 1)
	{
		isometric(&data->x, &data->y, z, data);
		isometric(&data->x1, &data->y1, z1, data);
	}
	data->x += data->shift_x;
	data->x1 += data->shift_x;
	data->y += data->shift_y;
	data->y1 += data->shift_y;
}

void	algo(t_data *data)
{
	float	step_x;
	float	step_y;
	float	max_v;

	controler(data);
	step_x = data->x1 - data->x;
	step_y = data->y1 - data->y;
	max_v = max(abs((int)step_x), abs((int)step_y));
	step_x /= max_v;
	step_y /= max_v;
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, data->color);
		data->x += step_x;
		data->y += step_y;
	}
}

void	set_coordinates(t_data *data, int x, int y, int check)
{
	if (check == 0)
	{
		data->x = x;
		data->x1 = x + 1;
		data->y = y;
		data->y1 = y;
	}
	if (check == 1)
	{
		data->x = x;
		data->x1 = x;
		data->y = y;
		data->y1 = y + 1;
	}
	algo(data);
}

void	draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	menu(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width -1)
				set_coordinates(data, x, y, 0);
			if (y < data->height -1)
				set_coordinates(data, x, y, 1);
			x++;
		}
		y++;
	}
}
