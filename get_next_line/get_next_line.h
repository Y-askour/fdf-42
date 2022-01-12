/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:17:54 by yaskour           #+#    #+#             */
/*   Updated: 2022/01/10 15:30:06 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 400
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin_g(char *s1, char *s2);
int		is_nl(char *s);
char	*ft_strdup_g(char *src);
int		ft_strlen_g(char *str);
char	*new_line(char *line);
char	*new_remain(char *line, char *remain);
char	*read_file(int fd, int *end);
#endif
