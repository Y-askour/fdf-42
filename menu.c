/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:49:26 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/14 18:10:55 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ato_h(char *hex)
{
	int length;
	int base;
	int decimal;

	length = ft_strlen(hex) - 1;
	base = 1;
	decimal = 0;
	while( length >= 0)
	{
		if (hex[length] >= '0' && hex[length] <= '9')
		{
			decimal += (hex[length] - 48 ) * base;
			base *= 16;
		}
		if (hex[length] >= 'A' && hex[length] <= 'F')
		{
			decimal += (hex[length] - 55) * base;
			base *= 16;
		}
		if (hex[length] >= 'a' && hex[length] <= 'f')
		{
			decimal += (hex[length] - 87) * base;
			base *= 16;
		}
		length--;
	}
	return (decimal);
}

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
