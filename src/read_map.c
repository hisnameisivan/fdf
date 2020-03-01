/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:11:13 by waddam            #+#    #+#             */
/*   Updated: 2020/03/01 23:12:11 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			read_map(int fd, t_map *map)
{
	int		res;
	char	*line;
	char	**z_line;
	t_point	*begin;
	int		cnt_pnts;

	cnt_pnts = 0;
	line = NULL;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (!(z_line = ft_strsplit(line, ' ')))
			break ;
		if (parsing(z_line, &begin, &cnt_pnts, map) == -1)
			return (-1);
	}
	free(line);
	return (res);
}
