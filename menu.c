/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:49:26 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/12 18:19:58 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	menu(t_data *data)
{
	int	width;
	int	height;

	data->xpm_img = mlx_xpm_file_to_image(data->mlx,
			"image/pic.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->xpm_img, 0, 0);
}
