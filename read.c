/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:48:44 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/14 14:22:20 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *filename)
{
	int		fd;
	char	**d;
	int		i;
	int		j;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	d = ft_split(line, ' ');
	i = 0;
	while (d[i])
		i++;
	j = 0;
	while (d[j])
		free(d[j++]);
	free(d);
	free(line);
	return (i);
}

int	get_height(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

void	fill_map(int *nums,int *color,char *line)
{
	char	**s_line;
	int		i;
	int		j;
	//int		k;

	i = 0;
	s_line = ft_split(line, ' ');
	color = 0;
	while (s_line[i])
	{
		nums[i] = ft_atoi(s_line[i]);
	//	k = 0;
	//	while(s_line[i][k] != ',')
	//		k++;
	//	k++;
	//	color[i] = ft_atoi(&s_line[i][k]);
		i++;
	}
	j = 0;
	while (s_line[j])
		free(s_line[j++]);
	free(s_line);
}

int	check_dir(char *filename)
{
	int		nb;
	int		fd;
	char	*buf;

	fd = open(filename, O_RDONLY);
	buf = malloc(sizeof(char) * 2);
	nb = read(fd, buf, 2);
	if (nb < 0)
		return (1);
	free(buf);
	return (0);
}

void	read_fdf(char *filename, t_data *ptr)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || check_dir(filename))
	{
		ft_putstr_fd("check file path\n", 1);
		exit(1);
	}
	i = 0;
	ptr->width = get_width(filename);
	ptr->height = get_height(filename);
	printf("%d,%d\n",ptr->height,ptr->width);
	ptr->map = (int **) malloc(sizeof(int *) * ptr->height + 1);
	//ptr->color_map = (int **) malloc(sizeof(int *) * ptr->height + 1);
	while (i < ptr->height)
	{
		ptr->map[i] = (int *) malloc(sizeof(int) * ptr->width);
		//ptr->color_map[i] = (int *) malloc(sizeof(int) * ptr->width);
		line = get_next_line(fd);
		fill_map(ptr->map[i], ptr->color_map[i], line);
		free(line);
		i++;
	}
	ptr->map[i] = NULL;
}
