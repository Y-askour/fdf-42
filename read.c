/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:48:44 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/12 15:11:57 by yaskour          ###   ########.fr       */
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

void	fill_map(int *nums, char *line)
{
	char	**s_line;
	int		i;
	int		j;

	i = 0;
	s_line = ft_split(line, ' ');
	while (s_line[i])
	{
		nums[i] = ft_atoi(s_line[i]);
		i++;
	}
	j = 0;
	while (s_line[j])
		free(s_line[j++]);
	free(s_line);
}

void	read_fdf(char *filename, t_data *ptr)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	ptr->width = get_width(filename);
	ptr->height = get_height(filename);
	ptr->map = (int **) malloc(sizeof(int *) * ptr->height);
	fd = open(filename, O_RDONLY);
	while (i < ptr->height)
	{
		ptr->map[i] = (int *) malloc(sizeof(int) * (ptr->width + 1));
		line = get_next_line(fd);
		fill_map(ptr->map[i], line);
		free(line);
		i++;
	}
}
