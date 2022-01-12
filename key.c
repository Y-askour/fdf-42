/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:02:03 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/12 18:49:20 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	press(int key, t_data *data)
{
	int	i;

	i = 0;
	mlx_clear_window(data->mlx, data->win);
	if (key == 53)
	{
		while (data->map[i])
			free(data->map[i]);
		free(data->map);
		exit(0);
	}
	draw(data);
	return (0);
}
