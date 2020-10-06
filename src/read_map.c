/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:11:13 by draudrau          #+#    #+#             */
/*   Updated: 2020/09/30 03:17:57 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	clean(char **line, char ***z_line)
{
	free_multiline(z_line);
	ft_strdel(line);
}

int			read_map(int fd, t_map *map, t_point **points)
{
	int		res;
	char	*line;
	char	**z_line;

	line = NULL;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if ((z_line = ft_strsplit(line, ' ')) != NULL)
		{
			if (parsing(z_line, points, map) == -1)
			{
				clean(&line, &z_line);
				return (-1);
			}
			clean(&line, &z_line);
		}
		else
			break ;
	}
	(line != NULL) ? free(line) : (line = NULL);
	if (res < 0 || map->width == 0)
		return (-1);
	return (0);
}
