/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:11:13 by waddam            #+#    #+#             */
/*   Updated: 2020/03/04 00:51:42 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
// #include "../includes/fdf.h"

t_point		*read_map(int fd, t_map *map)
{
	int		res;
	char	*line;
	char	**z_line;
	t_point	*points;

	line = NULL;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (!(z_line = ft_strsplit(line, ' ')))
			break ;
		if (parsing(z_line, &points, map) == -1)
			return (NULL);
		map->height++;
		free_multiline(&z_line);
		ft_strdel(&line);
	}
	if (res < 0 || map->width == 0)
		return (NULL);
	return (points);
}
