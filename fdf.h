/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:00:42 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/14 12:00:04 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "libft/libft.h"
# define win_width 2880
# define win_height 1800
typedef struct data
{
	void	*mlx;
	void	*xpm_img;
	void	*win;
	int		height;
	int		width;
	int		**map;
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		p;
	float	anglex;
	float	angley;
	int		depth;
}	t_data;

int		get_width(char *filename);
int		get_height(char *filename);
void	read_fdf(char *filename, t_data *ptr);
void	draw(t_data *data);
void	algo(t_data *data);
int		press(int key, t_data *data);
int		mouseh(int button, int x, int y, t_data *data);
void	menu(t_data *data);
float	max(float a, float b);
#endif
